#include<iostream>
#include<stdlib.h>
#include<fstream>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;
//HammingCode

int main()
{
	//system("clear");
	char cw[7],i,fd;
	cout<<"\nEnter 4 data bits resp. : ";
	cin>>cw[2]>>cw[4]>>cw[5]>>cw[6];
	cw[0]= cw[2] ^ cw[4] ^ cw[6];
	cw[1]= cw[2] ^ cw[5] ^ cw[6];
	cw[3]= cw[4] ^ cw[5] ^ cw[6];
	cout<<"Code word generated is  : ";
	for(i=0; i<7; i++)
		cout<<cw[i];
	
	char * myfifo = "/tmp/myfifo";

	mkfifo(myfifo, 0666);
	fd = open(myfifo, O_WRONLY);
    	write(fd, cw, sizeof(cw));
    	close(fd);
    	unlink(myfifo);

	cout<<endl;
	return 0;
}
/*OUTPUT
Enter 4 data bits resp. : 1010
Code word generated is  : 1011010
*/
