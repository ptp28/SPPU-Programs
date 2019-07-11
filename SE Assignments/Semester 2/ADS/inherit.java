import java.util.Scanner;
import java.util.*;

class Employee
 {
  public int id;
  private String name;
  protected long sal;
  
  Scanner sc = new Scanner(System.in);
  
  public void accept()
   {
    System.out.println("Enter the ID of the Employee");
    id = sc.nextInt();
    System.out.println("Enter the Name of the Employee");
    name = sc.next();
    System.out.println("Enter the Salary of the Employee");
    sal = sc.nextLong();
   }
   
   public void display()
    {
     System.out.println("ID: " + id);
     System.out.println("Name: " + name);
     System.out.println("Salary: " + sal);
    }
 }
 
 
 class Manager extends Employee
  {
    
    public void update_salary(long al)
     {
      sal = sal + al;
      System.out.println("The total Salary of the Employee is " + sal);
     }
      
  }
  
  class inherit
   {
    public static void main(String args[])
     {
      int ch,eid;
      long r;
      int n;
    
      Manager m[] = new Manager[10];
      for (int i = 0; i < 10; i++) 
        {
		m[i] = new Manager();
        }
      Scanner sc = new Scanner(System.in);
      System.out.println("How many Employees you want to create");
      n = sc.nextInt();
      
      do
       {
        System.out.println("1.Create Database");
        System.out.println("2.Display Database");
        System.out.println("3.Give Allowance");
        System.out.println("4.Search an Employee");
        System.out.println("5.Exit");
        System.out.println("6.Enter your Choice");
        ch = sc.nextInt();
        switch(ch)
         {
          case 1: 
                  for(int i=0;i<n;i++)
                  {
                   m[i].accept();
                  }
                  break;
                  
          case 2: for(int i=0;i<n;i++)
                {
                 m[i].display();
                }
                break;
                
          case 3: for(int i=0;i<n;i++)
                {
                 System.out.println("Enter the Allowance");
                 r = sc.nextLong();
                 m[i].update_salary(r);
                }
                break;
                
          case 4: System.out.println("Enter the ID of the Employee you want to search");
                eid = sc.nextInt();
                search(eid, m);
                break;
               
        }
        
       }while(ch!=5);
       
      }

      
      public static void search(int id1, Manager[] m)
     {
      int flag = 0;
      for(int i=0;i<m.length;i++)
       {
        if(m[i].id == id1)
         {
          flag=1;
          break;
         }
        }
        if(flag==1)
         {
          System.out.println("Employee Found !!");
         }
         else
           {
            System.out.println("Employee not Found");
           }  
      }
      
   }
    
