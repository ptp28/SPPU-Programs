#include <stdio.h>
void accept(char str[]);
void display(char str[]);
int length(char str[]);
void palindrome(char str[]);
void chardelete(char str[]);
void delete(char str[]);
void frequency(char str[]);
void replace(char str[]);
int main()
{
    int choice;
    char str[100];
    accept(str);
    display(str);
    do
    {
    printf("\n1.Check if Palindrome\n2.Delete a character\n3.Delete substring\n4.Frequency of characters\n5.Replace a substring\n6.Exit");
    printf("\nEnter your choice :");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
    palindrome(str);
    break;
    case 2:
    chardelete(str);
    display(str);
    break;
    case 3:
    delete(str);
    display(str);
    break;
    case 4:
    frequency(str);
    break;
    case 5:
    replace(str);
    display(str);
    break;
    case 6:printf("\n\n\nExiting....");
    break;
    default:printf("Wrong choice entered.\nTry again.......\n\n");
    }
    }while(choice!=6);
}
void accept(char str[])
{
    printf("\nEnter a string : ");
    scanf("%s",str);

}
void display(char str[])
{
    printf("\n\n**************\n\n");
    printf("\nTHE STRING IS : ");
    printf("\n%s",str);
    printf("\n\n**************\n\n");
    
}
int length(char str[])
{
	int len=0;
	while(str[len]!='\0')
	{
		len++;
	}
	return len;
}
void palindrome(char str[])
{
    int i,j,count=0;
    for(i=0,j=length(str)-1;i<length(str);i++,j--)
    {
        if(str[i]==str[j])
            count++;
    }
    printf("\n\n**************\n");
    if(count==length(str))
        printf("\nThe entered string is a palindrome string");
    else
        printf("\nThe entered string is not a palindrome string");
    printf("\n\n**************\n");
}
void chardelete(char str[])
{
    int i,j,count=0;
    char ch;
    printf("\nEnter the character you want to delete :");
    scanf(" %c",&ch);
    for(i=0;i<length(str);i++)
    {
        if(str[i]==ch)
        {
            for(j=i;j<length(str)-1;j++)
            {
                str[j]=str[j+1];
            }
            count++;
        }
    }
    if(count==0)
    	printf("\n\n**** Character not found ****\n\n");
    str[length(str)-count]='\0';
}
void delete(char str[])
{
     int start,len;
     int i,j;
     printf("\nEnter the starting address and number of character to delete : ");
     printf("\nStarting - ");
     scanf("%d",&start);
     printf("\nLength - ");
     scanf("%d",&len);
     for(i=0;i<len;i++)
     {
         for(j=start;j<(length(str)-1);j++)
         {
             str[j]=str[j+1];
         }
     }
     str[length(str)-len]='\0';
}
void frequency(char str[])
{
    int i,j,flag=0,count=0;
    printf("\n\n**************\n");
    for(i=0;i<length(str);i++)
    {
        for(j=0;j<length(str);j++)
        {
            if(j<i && str[i]==str[j])
            {
                flag=1;
            }
	    if(str[i]==str[j])
            {
                count++;
            }
        }
        if(flag==0)
        {
            printf("\nThe letter  '%c' occurs %d times ",str[i],count);
        }
        flag=0;
        count=0;
    }
    printf("\n\n**************\n");
}
void replace(char str[])
{
	char str1[100],str2[100],str3[100];
	int count=0,l1,l2,loc;
	printf("\nEnter the substring to be searched :");
	scanf("%s",str1);
	printf("\nEnter the substring to be replaced : ");
	scanf("%s",str2);
	int i,j,k=0;
	l1=length(str1);
	l2=length(str2);
	for(i=0,j=0;i<length(str);i++)
	{
	count=0;
		if(str[i]==str1[0])
		{	
			for(j=i,k=0;j<l1+i;j++,k++)
			{
				if(str[j]==str1[k])
				{
					count++;
				}
			}
			if(count==l1)
			{
				for(k=0;j<length(str);j++,k++)
				{
					str3[k]=str[j];
				}
					loc=i;
			}		
		}
	}
	i=0,j=loc;
	while(str2[i]!='\0')
	{
		str[j]=str2[i];
		i++;
		j ++;
		loc++;
	}
	i=0,j=loc;
	while(str3[i]!='\0')
	{
		str[j]=str3[i];
		i++;
		j++;
	}
	str[loc+length(str3)]='\0';
}

/*
Enter a string : parthparikh


**************


THE STRING IS : 
parthparikh

**************


1.Check if Palindrome
2.Delete a character
3.Delete substring
4.Frequency of characters
5.Replace a substring
6.Exit
Enter your choice :1


**************

The entered string is not a palindrome string

**************

1.Check if Palindrome
2.Delete a character
3.Delete substring
4.Frequency of characters
5.Replace a substring
6.Exit
Enter your choice :2

Enter the character you want to delete :p


**************


THE STRING IS : 
artharikh

**************


1.Check if Palindrome
2.Delete a character
3.Delete substring
4.Frequency of characters
5.Replace a substring
6.Exit
Enter your choice :3

Enter the starting address and number of character to delete : 
Starting - 1

Length - 2


**************


THE STRING IS : 
aharikh

**************


1.Check if Palindrome
2.Delete a character
3.Delete substring
4.Frequency of characters
5.Replace a substring
6.Exit
Enter your choice :4


**************

The letter  'a' occurs 2 times 
The letter  'h' occurs 2 times 
The letter  'r' occurs 1 times 
The letter  'i' occurs 1 times 
The letter  'k' occurs 1 times 

**************

1.Check if Palindrome
2.Delete a character
3.Delete substring
4.Frequency of characters
5.Replace a substring
6.Exit
Enter your choice :5

Enter the substring to be searched :aha

Enter the substring to be replaced : parth


**************


THE STRING IS : 
parthrikh

**************


1.Check if Palindrome
2.Delete a character
3.Delete substring
4.Frequency of characters
5.Replace a substring
6.Exit
Enter your choice :6



Exiting....
*/
