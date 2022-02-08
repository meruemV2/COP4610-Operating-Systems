#include "types.h"
#include "stat.h"
#include "user.h"

int main() {
  // create a child process and call fork
  int pid = fork();

  if(pid < 0) {
     printf(1, "Error forking!\n");
  } else if (pid == 0) {

    setpriority(0);
    int i = 0;
    for(; i < 10000; i++);
    printf(1, "Child is finished...\n");

  } else {
    setpriority(100);
    int i = 0;

    for(; i < 10; i++); //Loop a bit

    printf(1, "Parent is finished...\n");

    // parent process must wait for child to exit
    wait();

    printf(1, "Child finished...\n");
    printf(1, "Parent exit...\n");
  }
  exit();
}
