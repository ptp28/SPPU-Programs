import java.util.*;

public class calJNI
{
  static{
  System.loadLibrary("calc");
  }
  
  
  private native int add(int a, int b);
  private native int sub(int a, int b);
  private native int mul(int a, int b);
  private native int div(int a, int b);
  
  public static void main(String args[])
  {
     int cho;
     Scanner sc = new Scanner(System.in);
     do
      {
       System.out.println("1.Addition");
       System.out.println("2.Subtraction");
       System.out.println("3.Multiplication");
       System.out.println("4.Division");
       System.out.println("0.Exit");
       System.out.println("Enter the Operation");
       cho = sc.nextInt();
       switch(cho)
       {
         case 1: System.out.println("The Addition is :"+ new calJNI().add(30,20));
                 break;
              
         case 2: System.out.println("The Subtraction is :"+ new calJNI().sub(30,20));
                 break;
                 
         case 3: System.out.println("The Multiplication is :"+ new calJNI().mul(20,30));
                 break;
                 
         case 4: System.out.println("The Division is :"+ new calJNI().div(30,15));
                 break;
                 
         case 0: System.out.println("Exiting now...");
       
       }
      }while(cho!=0);
       
  }
  
}
