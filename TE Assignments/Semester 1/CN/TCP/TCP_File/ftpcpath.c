#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>


int main()

{

        int sock, bytes_recieved,choice,no1,no2,ans;  
        char read_data[1024],recv_data[1024],filename[100];
        struct hostent *host;
        struct sockaddr_in server_addr;  

        host = gethostbyname("127.0.0.1");

        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            perror("Socket");
            exit(1);
        }

        server_addr.sin_family = AF_INET;     
        server_addr.sin_port = htons(8888);   
        server_addr.sin_addr = *((struct in_addr *)host->h_addr);
        bzero(&(server_addr.sin_zero),8); 

        if (connect(sock, (struct sockaddr *)&server_addr,
                    sizeof(struct sockaddr)) == -1) 
        {
            perror("Connect");
            exit(1);
        }else{
        	printf("\nConnected successfully to server \n");
	}
	FILE *fp;
	printf("Enter name of file to transfer : ");
	scanf("%s",filename);
	fp = fopen(filename,"r+");
	fread(read_data,1,1024,fp);
	send(sock,read_data,1024,0);
	printf("File has been send");
	
	fclose(fp);
	close(sock);
	return 0;
}


