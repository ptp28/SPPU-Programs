#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int main(){
	
	char buffer[256],i;
	
	int socketfd=socket(AF_INET,SOCK_STREAM,0);
	if(socketfd<0){
		printf("\nError in the client socket");
		return 0;
	}
	
	struct sockaddr_in server_address,client_address;
	client_address.sin_family=AF_INET;
	client_address.sin_port=htons(atoi("8080"));
	client_address.sin_addr.s_addr=inet_addr(("127.0.0.1"));
	
	int len=sizeof(struct sockaddr_in);
	int b_check=connect(socketfd,(struct sockaddr*)&client_address,len);
	if(b_check<0){
		printf("Error in bind");
		return 0;
	}
	
	while(1){
		bzero(buffer,256);
		printf("\nEnter the message");
		scanf("%s",buffer);
		write(socketfd,buffer,sizeof(buffer));
		read(socketfd,buffer,sizeof(buffer));
		printf("Server says: %s",buffer);
		if(!(strcmp(buffer,"bye"))){
			break;
		}
		close(socketfd);
		return 0;
	}
}

