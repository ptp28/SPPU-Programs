#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
  pid_t pid, ppid;

  //get the process'es pid
  pid = getpid();

  //get the parrent of this process'es pid
  ppid = getppid();


  printf("My pid is: %d\n",pid);
  printf("My parent's pid is %d\n", ppid);

  return 0;
}
