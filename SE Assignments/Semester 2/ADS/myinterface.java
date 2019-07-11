import java.util.Scanner;
import java.util.*;

interface stack
 {
  public void push(int item);
  public int pop();
 }
 
 interface display
  {
   public void show();
  }
  
  class stack1 implements stack,display		//inheriting 
  {
   private int a[] = new int[20];
   private int tos = -1;		//top=tos =-1 since nothing in the stack
   
   public void push(int item)
   {
    if(tos == a.length-1)		//19?
     {
       System.out.println("The Stack is Full");
     }
     else
       {
        a[++tos] = item;
       }
    }
    
    public int pop()
     {
      if(tos < 0)
       {
        System.out.println("Stack Underflow");
        return 0;
       }
       else
         {
          return a[tos--]; //post decreament
         }
      }
      
      public void show()
       {
        System.out.println("The Elements in the Stack are");
        for(int i=0;i<=tos;i++)
         {
          System.out.println("Element:" + a[i]);
         }
       }
   }
   
   class Node
    {
     int data;
     Node next;
    }
   
   
   class stack2 implements stack,display		//for implementation of link list
    {
     Node start;
     public void push(int item)
      {
       Node temp;
       temp = new Node();
       temp.data = item;
       temp.next = null;
       if(start == null)
       {
        start = temp;
    	}
       else
        {
			temp.next = start;
			start = temp;  
  		}
      }
      
      public int pop()
      {
      	int lastNodeData = 0;
      	if (start.next != null) 
      		{
			lastNodeData = start.next.data;
			start = start.next;
		}
		return lastNodeData;
      }
      
      public void show()
      {
       Node temp = start;
       while(temp!=null)
        {
         System.out.println("Element:" + temp.data);
         temp = temp.next;
        }
      }
   }
       
   class myinterface
    {
     public static void main(String args[])
     {
      int n,m;
      int p,r;
      int x,y;
      stack1 sta = new stack1();
      Scanner sc = new Scanner(System.in);
      System.out.println("How many numbers you want in the stack");
      n = sc.nextInt();
      for(int i=0;i<n;i++)
       {
        System.out.println("Enter the number");
        m = sc.nextInt();
        sta.push(m);		//pushing m in array wala stack
       }
       sta.show();
       
       System.out.println("How many you want to pop");
       x = sc.nextInt();
       for(int i=0;i<x;i++)
       {
        sta.pop();
        System.out.println("");
       }
        sta.show();
        
        
       
       stack2 s1 = new stack2();
       stack s;
       display d;
       s = s1;
       d = s1;
       System.out.println("How many numbers you want in the stack");
       p = sc.nextInt();
       for(int i=0;i<p;i++)
       {
        System.out.println("Enter the number");
        r = sc.nextInt();
        s.push(r);
       }
       
       System.out.println("The Elements in the stack are");
       d.show();
       
       System.out.println("How many you want to pop");
       y = sc.nextInt();
       for(int i=0;i<y;i++)
       {
         s.pop();
         System.out.println("");
        d.show();
       }
     }
    }
    

