#include <stdio.h>
void accept(int x,int y,int a[][y]);
void display(int x,int y,int a[][y]);
void trans(int x,int y,int a[][y]);
void ut(int x,int y,int a[][y]);
void lt(int x,int y,int a[][y]);
void diasum(int x,int y,int a[][y]);
void add(int p,int q,int a[][q],int b[][q]);
void sub(int p,int q,int a[][q],int b[][q]);
void mul(int p,int q,int a[][q],int b[][q]);
int main()
{
	int i,j,x,y;
	printf("\n\nEnter the number of rows and columns of the matrix :\n");
	scanf("%d%d",&i,&j);
	int mat1[i][j];
	accept(i,j,mat1);
	display(i,j,mat1);
	trans(i,j,mat1);
	ut(i,j,mat1);
	lt(i,j,mat1);
	diasum(i,j,mat1);
	printf("\n\nENTER THE SECOND MATRIX");
	printf("\nEnter the number of rows and columns of the 2nd matrix :\n");
	scanf("%d%d",&x,&y);
	int mat2[x][y];
	accept(x,y,mat2);
	if(x==i && y==j)
	{
		add(i,j,mat1,mat2);
		sub(i,j,mat1,mat2);
	}
	else
	{
		printf("\n\nAddition of the two entered matrices is not possible ");
		printf("\n\nSubtraction of the two entered matrices is not possible \n");
	}
	if(i==y)
		mul(i,j,mat1,mat2);
	else
		printf("\n\nMultiplication of the two entered matrices is not possible ");
}
void accept(int x,int y,int a[][y])
{
	int i,j;
	printf("\nEnter the matrix :\n");
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			scanf("%d",&a[i][j]);
		}
		printf("\n");
	}
}
void display(int x,int y,int a[][y])
{
	int i,j;
	printf("\nEntered matrix is :\n");
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}
void trans(int x,int y,int a[][y])
{
	printf("\nThe transpose of the entered matrix is :\n");
	int i,j,flag=0;
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			printf("%d\t",a[j][i]);
		}
		printf("\n");
	}
}
void ut(int x,int y,int a[][y])
{
	printf("\nThe upper triangular matrix of the entered matrix is :\n");
	int i,j,flag=0;
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			if(i>j)
				printf("0\t");
			else
				printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}
void lt(int x,int y,int a[][y])
{
	printf("\nThe lower triangular matrix of the entered matrix is :\n");
	int i,j;
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			if(i<j)
				printf("0\t");
			else
				printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}
void diasum(int x,int y,int a[][y])
{
	printf("\nThe sum of the diagonal elements of the matrix is : ");
	int i,j,sum=0;
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			if(i==j)
				sum=sum+a[i][j];
		}
	}
	printf("%d\n",sum);
}
void add(int p,int q,int a[][q],int b[][q])
{
	int i,j;
	printf("\nThe addition of the two matrices is : \n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++)
		{
			printf("%d\t",a[i][j]+b[i][j]);
		}
		printf("\n");
	}
}
void sub(int p,int q,int a[][q],int b[][q])
{
	int i,j;
	printf("\nThe subtraction of the two matrices is : \n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++)
		{
			printf("%d\t",a[i][j]-b[i][j]);
		}
		printf("\n");
	}
}
void mul(int p,int q,int a[][q],int b[][q])
{
	int i,j,k,mul=0;
	printf("\nThe multiplication of the two matrices is : \n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++)
		{	
			for(k=0;k<q;k++)
				mul=mul+(a[i][k]*b[k][j]);
			printf("%d\t",mul);
            mul=0;
		}
		printf("\n");
	}
}



/*
 Enter the number of rows and columns of the matrix :
 3
 3
 
 Enter the matrix :
 1
 2
 3
 
 4
 5
 6
 
 7
 8
 9
 
 
 Entered matrix is :
 1	2	3
 4	5	6
 7	8	9
 
 The transpose of the entered matrix is :
 1	4	7
 2	5	8
 3	6	9
 
 The upper triangular matrix of the entered matrix is :
 1	2	3
 0	5	6
 0	0	9
 
 The lower triangular matrix of the entered matrix is :
 1	0	0
 4	5	0
 7	8	9
 
 The sum of the diagonal elements of the matrix is : 15
 
 
 ENTER THE SECOND MATRIX
 Enter the number of rows and columns of the 2nd matrix :
 
 2
 2
 
 Enter the matrix :
 1
 2
 
 3
 4
 
 
 
 Addition of the two entered matrices is not possible
 
 Subtraction of the two entered matrices is not possible
 
 
 Multiplication of the two entered matrices is not possible
 
 
 
 Enter the number of rows and columns of the matrix :
 3
 3
 
 Enter the matrix :
 1
 2
 3
 
 4
 5
 6
 
 7
 8
 9
 
 
 Entered matrix is :
 1	2	3
 4	5	6
 7	8	9
 
 The transpose of the entered matrix is :
 1	4	7
 2	5	8
 3	6	9
 
 The upper triangular matrix of the entered matrix is :
 1	2	3
 0	5	6
 0	0	9
 
 The lower triangular matrix of the entered matrix is :
 1	0	0
 4	5	0
 7	8	9
 
 The sum of the diagonal elements of the matrix is : 15
 
 
 ENTER THE SECOND MATRIX
 Enter the number of rows and columns of the 2nd matrix :
 3
 3
 
 Enter the matrix :
 1
 2
 3
 
 4
 5
 6
 
 7
 8
 9
 
 
 The addition of the two matrices is :
 2	4	6
 8	10	12
 14	16	18
 
 The subtraction of the two matrices is :
 0	0	0	
 0	0	0	
 0	0	0	
 
 The multiplication of the two matrices is : 
 30	36	42	
 66	81	96	
 102	126	150
*/
