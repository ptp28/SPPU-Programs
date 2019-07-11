#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main(){

  pid_t c_pid;


  c_pid = fork();
  if( c_pid == 0 ){
	printf("Child: I'm the child: %d\n", c_pid);
  }
  else if (c_pid > 0){
	printf("Parent: I'm the parent: %d\n", c_pid);
  }
  else{
	perror("fork failed");
        _exit(2);
 }
 
 return 0;
                                                                                                                                                  
}
