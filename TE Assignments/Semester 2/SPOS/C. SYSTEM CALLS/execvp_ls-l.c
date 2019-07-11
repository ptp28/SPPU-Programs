#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[]){

  //argv array for: ls -l
  char * ls_args[] = { "ls" , "-l", NULL};
  //                    ^ 
  //  use the name ls
  //  rather than the
  //  path to /bin/ls
  execvp(   ls_args[0],     ls_args);

  //only get here on error
  perror("execv");
  return 2;
}

