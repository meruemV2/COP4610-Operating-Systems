// Jerry Laplante
// October 3 2021
// COP 4610
// Proj 2

#include "types.h"
#include "stat.h"
#include "user.h"
#include "uproc.h"
#define MAXPROC 64

int
main(int argc, char *argv[])
{
  // declare  uproc struct
  struct uproc *prs = malloc(MAXPROC*sizeof(struct uproc));
  // call getprocs in kernel space
  int num = getprocs(MAXPROC, prs);
  if(num == -1){
    printf(1, "Kernel returned an error when getting processes. \n");
    exit();
  }
  int i=0;
  for(; i< num; i++) {
    if(prs[i].pid == 1){
      printf(1, "%s[%d] \n", prs[i].name, prs[i].pid-1); // init is 1
    }else if(prs[i].ppid == 1){
      printf(1, "   %s[%d] \n", prs[i].name, prs[i].pid-1); // child of init
    }else {
      printf(1, "      %s[%d] \n", prs[i].name, prs[i].pid-1); // else is grandchild
    }
  }
  exit();
}
