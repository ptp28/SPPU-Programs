#include<stdio.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char buffer[1024],c;int i=0;
	int clifd=socket(AF_INET,SOCK_STREAM,0);
	if((clifd<0))
	{
		printf("Error In creation of socket\n");
		return 0;
	}
	struct sockaddr_in client_addr;
	client_addr.sin_family=AF_INET;
	client_addr.sin_port=htons(atoi("7777"));
	client_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	int len=sizeof(struct sockaddr_in);

	int conn=connect(clifd,(struct sockaddr*)&client_addr,len);
	bzero(buffer,256);

      	int choice;
      	printf("Enter the operation you want to perform:\n");
      	printf("1)Addition\n2)Subtraction\n3)Multiplication\n4)Division\n");
      	scanf("%d",&choice);
      	printf("Enter the operands:");
      	int a,b;
      	scanf("%d%d",&a,&b);
      	write(clifd,(char *) &a,sizeof(a));
      	write(clifd,(char *) &b,sizeof(b));
      	switch(choice)
      	{
 		case 1 :write(clifd,"add",4);
 			strcpy(buffer,"Addition is:");
 			break;     	
 		case 2 :write(clifd,"sub",4);
 			strcpy(buffer,"Subtraction is:");
 			break;     	
 		case 3 :write(clifd,"mul",4);
 			strcpy(buffer,"Multiplication is:");
 			break;     	
 		case 4 :write(clifd,"div",4);
 			strcpy(buffer,"Division is:");
 			break;     		
 	}

 	read(clifd,(char * )&i,sizeof(i));
 	printf("%s%d",buffer,i);
 	close(clifd);
 }
