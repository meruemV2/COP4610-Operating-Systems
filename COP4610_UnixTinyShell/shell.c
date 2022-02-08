#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

void error()
{
  printf("Error: Invalid command...\n");
}
void  execute(char **argv)
{
    pid_t  pid;
    int    status;

    if ((pid = fork()) < 0)
    {     /* fork a child process           */
        error();
        exit(1);
    }
    else if (pid == 0)
    {          /* for the child process:         */
        if (execvp(*argv, argv) < 0)
        {     /* execute the command  */
            error();
            exit(1);
        }
    }
    else
        {                                  /* for the parent:      */
        while (wait(&status) != pid)       /* wait for completion  */
            ;
        }
}
// parse user input
void parse(char *ln[64], int num)
{
    int i;
    char *s=" \t\n";
    char *token;
    char *arg[64];
    int n=0;

    int nm=0;

 for(i=0; i < num; i++)
 {
    token= strtok(ln[i], s);
    while(token != NULL )
    {
        arg[n] = token;
      n++;
      token= strtok(NULL,s);
    }

  n++;
     arg[n - 1]= NULL;
  execute(arg);
  n=0;

 }
while( nm != num)
 {
    wait(NULL);
    nm++;
 }
}

// parsing for multi line arguments
void multiParse(char *ln)
{
  char *sm=";\n";
  char *token;
  int num=0;
  char * argv[64];
  token = strtok(ln,sm);

 while(token != NULL )
 {
      argv[num]=token;
      num++;
      token= strtok(NULL,sm);
 }
 if(strcmp(argv[0], "quit" )==0)
 {
    printf("Shutting down shell...");
    exit(0);
 }
  parse(argv, num);
}

// main routine while loop
int main (int argc, char *argv[])
{

  if(argc > 1)
  {
    FILE *f;

    char line[1024];

      f= fopen(argv[1], "r");

    if(f == NULL)
    {
      perror("Error: check file...");
      return(-1);
    }

   while(fgets(line, sizeof(line), f))
   {
       multiParse(line);
   }
  }
  else
    {
   char line[1024];

   printf("\nTinyShell ^_^ --> ");

   while(fgets(line, sizeof(line), stdin))
   {
       multiParse(line);

   printf("TinyShell ^_^ --> ");
   }
 }
}