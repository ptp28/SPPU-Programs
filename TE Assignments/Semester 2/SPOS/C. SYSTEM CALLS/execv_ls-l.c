/*execv_ls-l.c*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[]){

  //argv array for: /bin/ls -l
  char * ls_args[] = { "/bin/ls" , "-l", NULL};
  //                                  ^
  //       all argv arrays must be ___| 
  //       NULL terminated       

  //execute the program
  execv(   ls_args[0],     ls_args);
  //           ^              ^
  //           |              |
  // Name of program        argv array
  // is ls_args[0]          for ls_args


  //only get here on error
  perror("execv");
  return 2;
}

