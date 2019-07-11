#include<iostream>
#include<stdlib.h>
#include<fstream>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX_BUF 1024
//HammingCode

using namespace std;

int main()
{
	//system("clear");
	char cw[7],i,fd;
	char p[3];
	char buf[MAX_BUF];
	char t;
 	
	char * myfifo = "/tmp/myfifo";
	fd = open(myfifo, O_RDONLY);
   	read(fd, buf, MAX_BUF);
    	cout<<"Received Codeword: "<< buf;
    	close(fd);
	for( i=0; i<7; i++)
		cw[i]=buf[i];

	p[0]= cw[0] ^ cw[2] ^ cw[4] ^ cw[6];
	p[1]= cw[1] ^ cw[2] ^ cw[5] ^ cw[6];
	p[2]= cw[3] ^ cw[4] ^ cw[5] ^ cw[6];
	int count =0;
	if(p[0]||p[1]||p[2])
	{   	if(p[0]==1)
			count+=1;
		if(p[1]==1)
			count+=2;
		if(p[2]==1)
			count+=4;
		if(cw[count] ==1)
			cw[count]=0;
		else
			cw[count]=1;
		cout<<"\nCorrected 4 data bits resp. : ";
		for( i=0; i<7; i++)
			cout<<cw[i];
	}
	else
	{	cout<<"\nCorrectly received !";
		cout<<"\nReceived data bits : ";
		for( i=0; i<7; i++)
			if(!(i==0||i==1||i==3))			
				cout<<cw[i]<<" ";
	}
	return 0;
}
/*OUTPUT
Received Codeword: 1011010
Correctly received !
Received data bits : 1 0 1 0*/
