
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<error.h>


  void nerror(char *errMsg)
  {
      perror(errMsg);
      exit(1);
  }



  int main()
	{

                 struct sockaddr_in serverSock,clientSock;
                 double angle,result;
                 
                 int choice=0;

                 int sockFd = socket(AF_INET,SOCK_STREAM,0);  
             
                 if(sockFd == -1)
                 {
                           nerror("Socket Creation Error");
                           
                 }
                 
                 //Initialization of various fields in sockaddr_in struct instance
                 
                 serverSock.sin_family = AF_INET;               //IPv4 
                 serverSock.sin_port = htons(5050);
                 serverSock.sin_addr.s_addr = INADDR_ANY;
                 
                 //binding socket
                 int sockLen = sizeof(struct sockaddr_in);
                 int bindFlag = bind(sockFd,(struct sockaddr* )&serverSock,sockLen);
                 if(bindFlag==-1)
                 {
                     printf("Error in Binding..!");
                     return -1;
                 }
                 
                 //listening
                 int listenFlag = listen(sockFd,10) ;          //max. 10 client connections possible,incoming queue of size 10 is initialized
                 if(listenFlag == -1)
                 {
                      printf("Error in listening");
                      return -1;
                 }
                 
                 while(1)
                 {
                       //Accepting a connection
                  
                       int connFd = accept(sockFd,(struct sockaddr*)&clientSock,&sockLen);
                       if(connFd==-1)
                       {
                         printf("Connection Failed..!");
                         return -1;
                    }  
                 read(sockFd,&choice,sizeof(choice));
                 read(sockfd,&angle,sizeof(angle));
                 
                 char operation[3];
                 
                 angle = angle*(PI/180);        //converting angle from degrees to radians
                 switch(choice)
                 {
                 
                      case 1: result = sin(angle);
                              strcpy(operation,"sin");
                              break;
                      
                      case 2: result = sin(angle);
                              strcpy(operation,"cos");
                              break;
                      case 3: result = sin(angle);
                              strcpy(operation,"tan");
                              break;
                      default:printf("Invalid Opearation..!");      
                }
                 printf("%s(%lf) = %lf")    
                 write(connFd,&result,sizeof(result));
                 
                      
                 }
                 
                 return 0;
                 }
