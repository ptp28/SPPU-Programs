#include<stdio.h>
struct student
{ 
  int rollno;
  char name[20];
  int marks;
};
void average(int num, struct student *p);
  void maxmin(int ,struct student * );
void mostmarks(int num,struct student p[]);
  void absent (int, struct student * );
  int main()
{
   int num,i;
   printf("enter the no. of students");
   scanf("%d",&num);
   struct student s[num];
   for(i=0;i<num;i++)
   {
       printf("\nEnter\n1.Roll no.\n2.Name\n3.Marks\nIf the student is absent enter-1 as marks");
       scanf("%d%s%d",&s[i].rollno,s[i].name,&s[i].marks);  //accept info
   }
   printf("Database is:\n");
   printf("Rollno\tName\tMarks\n");                    // set table
    for(i=0;i<num;i++)
    {
        printf("%d\t%s\t%d\t\n",s[i].rollno,s[i].name,s[i].marks);   //display info
    }
    printf("\n");
    average(num,s);
    printf("\n");               // function calls
    maxmin(num,s);
    printf("\n");
    mostmarks(num,s);
    printf("\n");
    absent(num,s);
    printf("\n");
    return 0;
}
 void maxmin(int num,struct student *p)
{
   int i,max,min;
    max=0;
    min=100;
    p++;
    for(i=1;i<num;i++)
  {
      if(p->marks>max)  
      max=p->marks;
      if(p->marks<min && p->marks!=-1)
         min=p->marks;
         p++;
  }
    printf("\nThe maximum marks are : %d",max);
    printf("\nThe minimum marks are : %d",min);
}
  void absent(int num,struct student *p)
  {
   int i,flag=0;
   printf("\nList of Absent Students is -");
    for(i=0;i<num;i++)
  {
    if(p->marks==-1)
    {
        flag=1;
        printf("\nRoll number %d \n",p->rollno);
    }
      p++;
  }
      if(flag==0)
      {
          printf("\n....\nThere are no absent students .");
      }
}
void average(int num,struct student *p)
{
    int i,sum=0,ab=0;
    float avg;
    for(i=0;i<num;i++)
    {
        if(p->marks!=-1)
        {
            sum=sum + p->marks;
        }
        else
            ab++;
        p++;
    }
    avg=sum/(num-ab);
    printf("The average of all the students is = %0.2f",avg);
}
void mostmarks(int num,struct student p[])
{
    int i,j,count=0,countf=0,n;
    for(i=0;i<num;i++)
    {
        for(j=i;j<num;j++)
        {
            if(p[i].marks==p[j].marks)
            {
                count++;
            }
        }
        if(countf<count)
        {
            countf=count;
            n=i;
        }
        count=0;
    }
    printf("\nThe most marks obtained :");
    printf("\n%d students obtained %d marks.",countf,p[n].marks);
}

/*
 Enter
 1.Roll no.
 2.Name
 3.Marks
 If the student is absent enter-1 as marks
 1
 p1
 99
 
 Enter
 1.Roll no.
 2.Name
 3.Marks
 If the student is absent enter-1 as marks
 2
 p2
 -1
 
 Enter
 1.Roll no.
 2.Name
 3.Marks
 If the student is absent enter-1 as marks
 3
 p3
 99
 
 Enter
 1.Roll no.
 2.Name
 3.Marks
 If the student is absent enter-1 as marks
 4
 p4
 77
 
 Database is:
 Rollno	Name	Marks
 1	p1	99
 2	p2	-1
 3	p3	99
 4	p4	77
 
 The average of all the students is = 99.00
 
 The maximum marks are : 99
 The minimum marks are : 77
 
 The most marks obtained :
 2 students obtained 99 marks.
 
 List of Absent Students is -
 Roll number 2 
*/
