#include<stdio.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<error.h>

void nerror(char *msg)
{
	perror(msg);
	exit(1);
}

int main()
{
	char buffer[256],c;
	int a,b;
	int sockfd=socket(AF_INET,SOCK_STREAM,0);
	printf("socket cretated successfull\n");


	if((sockfd<0))
	{
		nerror("Error In creation of socket\n");
		return 0;
	}
	int port_no;
	struct sockaddr_in server_addr,client_addr;
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(atoi("7777"));
	server_addr.sin_addr.s_addr=INADDR_ANY;
	int len=sizeof(struct sockaddr_in);
	int bind_check=bind(sockfd,(struct sockaddr *)&server_addr,len);
	printf("bind success\n");
	if((bind_check<0))
	{
		nerror("Error In Binding\n");
		return 0;
	}
	int listen_check=listen(sockfd,5);
	printf("listen success\n");
	printf("waiting for client\n");
	if((listen_check<0))
	{
		nerror("Error In Listening\n");
		return 0;
	}


	while(1)
	{

		int client_check=accept(sockfd,(struct sockaddr *)&client_addr,&len);
		if((client_check<0))
		{
			nerror("Error In Accepting\n");
			return 0;
		}
		printf("New Connection Found\n");
		//bzero(buffer,256);

	   	read(client_check,(char *)&a,sizeof(a));
	    	read(client_check,(char *)&b,sizeof(b));
	    	read(client_check,buffer,256);

		if(!(strcmp(buffer,"add")))
	    	{
	    		int c=a+b;
	    		write(client_check,(char *) &c,sizeof(c));
			printf("addition is %d\n",c);
	    	}
	    	else if(!(strcmp(buffer,"sub")))
	    	{
	    		int c=a-b;
	    		write(client_check,(char *) &c,sizeof(c));
			printf("substraction is %d\n",c);


	    	}
	    	else if(!(strcmp(buffer,"mul")))
	    	{
	    		int c=a*b;
	    		write(client_check,(char *) &c,sizeof(c));
			printf("mul is is %d\n",c);
	    	}
	    	else if(!(strcmp(buffer,"div")))
	    	{
	    		int c=a/b;
	    		write(client_check,(char *) &c,sizeof(c));
			printf("div is is %d\n",c);
	    	}
	    	close(client_check);
    		exit(1);
	}
}
