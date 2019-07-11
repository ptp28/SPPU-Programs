#include <sys/types.h> //Basic System Data types
#include <sys/socket.h>  // Structure needed by socket
#include <netinet/in.h>	//sockaddr_in() and other internet definitions
#include <arpa/inet.h>	//inet(3) functions
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>


int main()
{
        int sock, connected, bytes_received , true = 1,i,t1,t2,t3,choice=1;  
        char read_data [1024], received_data[1024],buffer[20];       

        struct sockaddr_in server_addr,client_addr;    
        int sin_size;
        printf("\n----------FILE TRANSFER SERVER----------\n");
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            perror("Socket");
            exit(1);
        }
        else{
        	printf("\nSocket created successfully\n");
	}
	if (setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&true,sizeof(int)) == -1) {
            perror("Setsockopt");
            exit(1);
        }
        
        server_addr.sin_family = AF_INET;         
        server_addr.sin_port = htons(8888);     
        server_addr.sin_addr.s_addr = INADDR_ANY; 
        bzero(&(server_addr.sin_zero),8); 

        if (bind(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr))== -1) {
            perror("Unable to bind");
            exit(1);
        }else{
        	printf("\nBind successful\n");
	}

        if (listen(sock, 5) == -1) {
            perror("Listen");
            exit(1);
        }else{
        	printf("\nListen successful\n");
	}
		
	printf("\n TCP Server Waiting for client");
        fflush(stdout);

	int s =sizeof(struct sockaddr_in);
	connected = accept(sock,(struct sockaddr *)&server_addr,&s);
	bytes_received = recv(connected,received_data,1024,0);
	FILE *fp;
	fp = fopen("receive.txt","w+");
	fwrite(received_data,1,1024,fp);
	fseek(fp, 0, SEEK_SET);
	fread(read_data,1,1024,fp);
	printf("\nData in receive.txt is : %s\n",read_data);
	fclose(fp);
	close(sock);
	return 0;
}

