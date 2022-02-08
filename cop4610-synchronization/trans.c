//        Jerry Laplante                                            */
//        COP 4610                                                   */
//        Assignment 5

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <errno.h>
#include <sys/wait.h>

#define READ_END      0
#define WRITE_END     1
#define BUFFER_SIZE          25

int checkForFile(const char * fn);

int main(int argc, char *argv[]){

    // variables needed
    char buffer[4096];
    char readMessage[BUFFER_SIZE];
    char writeMessage[BUFFER_SIZE];
    int v1 = -1;
    int v2;
    const int SIZE = 4096;
    const char *memObj = "jl14c_cop4610";
    int shm_fd;
    void *ptr;
    int blockNumber = 1;
    int blockSize = 0;
    char yn[3];
    char astr[5], bstr[5];
    char finstr[25];



    if(argc != 3 ){
        fprintf(stderr,"Three arguments command line arguments are necessary...\n");
        exit(1);
    }

    FILE *outFile; // output file
    FILE *inFile = fopen(argv[1], "rb"); // input file

    if(inFile == NULL){
        fprintf(stderr,"Error: could not open input file...\n");
        exit(1);
    }

    int check = checkForFile(argv[2]);
    if( check ){
        printf("This file already exists... Would you like to overwrite it..? (Y/N)\n");
        scanf("%s",yn);
        if( strcmp (yn, "yes") == 0 || strcmp (yn, "y") == 0 || strcmp (yn, "Y") == 0 ){
            outFile = fopen(argv[2], "w");
            if(outFile == NULL){
                fprintf(stderr,"Error: could not open output file...\n");
                exit(1);
            }
        }
        else{
            printf("Did not overwrite... Goodbye\n");
            exit(1);
        }
    }

    if(check == 0){
        outFile = fopen(argv[2], "w"); // open output file
        if(outFile == NULL){
            fprintf(stderr,"Error opening output file\n");
            exit(1);
        }
    }

    int p1[2]; //parent pipe
    int p2[2]; //child pipe

    if (pipe(p1) == -1){ //check parent sucess
        fprintf(stderr,"Parent Pipe Failed...\n");
        exit(1);
    }
    if (pipe(p2) == -1){ //check child success
        fprintf(stderr,"Parent Pipe Failed...\n");
        exit(1);
    }

    pid_t pid = fork();
    if (pid < 0) { // check fork success
        fprintf(stderr, "Fork failed");
        exit(1);
    }

    if (pid > 0) {
        shm_fd = shm_open(memObj, O_CREAT | O_RDWR, 0666); // open shared mem
        ftruncate(shm_fd,SIZE); // setup the size of segment

        // map shared memory segment in process address space
        ptr = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
        if (ptr == MAP_FAILED){
            fprintf(stderr, "Parent: Map has failed %d %s\n", blockNumber, strerror(errno));
            exit(1);
        }
        fseek(inFile, SEEK_SET, 0);

        close(p1[READ_END]);
        close(p2[WRITE_END]);

        while( 1 ){ // while routine
            blockSize = fread(buffer, 1, 4095, inFile);  // infile 4095 bytes at a time
            if(blockSize != 0){
                sprintf(ptr, "%s", buffer ); // write to shared memory
            }
            if(blockSize == 0)
                blockNumber = 0;
            sprintf(astr, "%d", blockNumber);
            sprintf(bstr, "%d", blockSize);
            strcpy(finstr, astr);
            strcat(finstr, " ");
            strcat(finstr, bstr);

            write(p1[WRITE_END], finstr, strlen(finstr) + 1); // write to pipe

            if(read(p2[READ_END], readMessage, BUFFER_SIZE) > 0 ){
                sscanf(readMessage, "%d", &v1);
            }
            else
                break;

            if(v1 == 0)
                break;
            ++blockNumber;
        }
        fclose(inFile);
        close(p1[WRITE_END]);
        close(p2[READ_END]);
    }//end parent


    else { // child process
        shm_fd = shm_open(memObj, O_RDONLY, 0666); // open shared memory again
        if (shm_fd == -1) {
            fprintf(stderr,"shared memory open has failed\n");
            exit(1);
        }

        ptr = mmap(0,SIZE, PROT_READ, MAP_SHARED, shm_fd, 0); // map memory segment again
        if (ptr == MAP_FAILED) {
            printf("Child: Map has failed\n");
            exit(1);
        }

        close(p1[WRITE_END]);  // close unused end of pipe
        close(p2[READ_END]);  // close unused end the pipe

        while(1){
            if(read(p1[READ_END], readMessage, BUFFER_SIZE) > 0 ){
                sscanf(readMessage, "%d %d", &v1, &v2); // child reads values of v1 and v2
            }
            else
                break;
            if(v1 != 0){
                sprintf(buffer, "%s", (char *)ptr);
                fwrite(buffer, 1, v2, outFile); // write to output file
            }

            sprintf(writeMessage, "%d", v1);

            write(p2[WRITE_END], writeMessage, strlen(writeMessage) + 1); // child writes
            if(v1 == 0)
                break;
        }
        fclose(outFile);
        close(p1[READ_END]);
        close(p2[WRITE_END]);


        if (shm_unlink(memObj) == -1) {// remove  shared memory segment
            fprintf(stderr, "Error: could not remove shared memory segment... %s\n", memObj);
            exit(1);
        }

    } // end child process

    return 0;
}

// routine to check files
int checkForFile(const char * fn)
{
    FILE *file = fopen(fn, "rb");
    if (file == NULL)
    {
        return 0;
    }
    fclose(file);
    return 1;
}
