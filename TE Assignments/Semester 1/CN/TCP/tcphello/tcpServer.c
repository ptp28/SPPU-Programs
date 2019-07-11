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
		printf("\nError in the socket");
		return 0;
	}
	
	struct sockaddr_in server_address,client_address;
	server_address.sin_family=AF_INET;
	server_address.sin_port=htons(atoi("8080"));
	server_address.sin_addr.s_addr=INADDR_ANY;
	
	int len=sizeof(struct sockaddr_in);
	int b_check=bind(socketfd,(struct sockaddr *)&server_address,len);
	if(b_check<0){
		printf("Error in bind");
		return 0;
	}
	int l_check=listen(socketfd,5);
	if(l_check<0){
		printf("Error in listening");
		return 0;
	}
	
	printf("\nWaiting for the client.....");
	int a_check=accept(socketfd,(struct sockaddr *)&client_address,&len);
	if(a_check<0){
	printf("Error in accept");
	}
	
	while(1){
		bzero(buffer,256);
		read(a_check,buffer,256);
		printf("\nClient says: %s",buffer);
		if(!(strcmp(buffer,"bye"))){
			break;
		}
		printf("\nEnter the message");
		scanf("%s",buffer);
		write(a_check,buffer,sizeof(buffer));
		close(socketfd);
		return 0;
	}
}
