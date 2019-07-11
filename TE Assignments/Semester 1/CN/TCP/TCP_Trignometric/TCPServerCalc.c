#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<error.h>
#include<math.h>

#define PI 3.142

  void nerror(char *errMsg)
  {
      perror(errMsg);
      exit(1);
  }



  int main()
	{

                 struct sockaddr_in serverSock,clientSock;
                 double angle,result,choice;
                 
                 int choice=0;

                 int sockFd = socket(AF_INET,SOCK_STREAM,0);  
             
                 if(sockFd == -1)
                 {
                           nerror("Socket Creation Error");
                           
                 }
                 
                 //Initialization of various fields in sockaddr_in struct instance
                 
                 serverSock.sin_family = AF_INET;                                       //IPv4 
                 serverSock.sin_port = htons(5050);
                 serverSock.sin_addr.s_addr = inet_addr("127.0.0.1");                   //localhost
                 
                 //binding socket
                 int sockLen = sizeof(struct sockaddr_in);
                 
               
                 int connFlag = connect(sockFd,(struct sockAddr*)&serverSock,sockLen);
                 if(connFlag==-1)
                 {
                     printf("Connection Failed..!");
                 
                     return -1;
                 } 
                  printf("\nEnter Trigonometric Operation Choice you want to perform:\n1.sine\n2.cosine\n3.tan\nEnter Your Choice : ");
                       scanf("%d",&choice);
                    
                    
         
                    
                       if(choice<1||choice>3) printf("\nInvalid Choice");
                       else
                       {
                       printf("\nEnter Angle in degrees:");
                       scanf("%lf",&angle);
                       
                       printf("You entered angle %lf:",angle);
                       
                       write(connFd,&choice,sizeof(choice));
                       write(connFd,&angle,sizeof(angle));                      
                      
                       read(connFd,&result,sizeof(result));
                       
                       
                       printf("Result is :\n%lf",result);
                      }
                      close(sockFd);
                      
                 }
                      
              return 0;
                      
                      
                 
                 
                 
                 
                 
                 
                 
	}

                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
               
                 
                 
                 
                 
                 
                 
	}





