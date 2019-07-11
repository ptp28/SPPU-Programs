import java.util.*;

class bank
{
    public long ac;
    public String name;
    public int bal;
    Scanner sc = new Scanner(System.in);
  
    public void accept()
    {
        int flag = 0;
        int a;
        System.out.println("\nEnter the following details : ");
        System.out.println("Name : ");
        name = sc.nextLine();
        System.out.println("Account Number : ");
        ac = sc.nextLong();
        try
        {
            System.out.println("Balance : ");
            bal = sc.nextInt();
        }
        catch(InputMismatchException ie)
        {
            System.out.println("Please Enter Balance as Integer Only");
        }
    }
    
    public void display()
    {
        System.out.println("The Name of the Customer is: " + name);
        System.out.println("The Account Number is: " + ac);
        System.out.println("The balance is: " + bal);
    }
     
     public void depo(int amt)
    {
        bal = bal + amt;
        System.out.println("Balance Updated Successfully");
        System.out.println("The new Balance is "+ bal);
    } 
     
    public void transaction(int amt)
    {
        bal = bal - amt;
        try
        {
            if(bal<5000)
            {
                bal = bal + amt;
                throw new Myexception();		//calling the const & allocating memory
            }
            else
            {
                System.out.println("The new balance is: " + bal);
            }
        }
        catch(Myexception m)	//
        {
            System.out.println("Transaction unsuccessful!!!");
            System.out.println("");
        }
    }
    
}
 
 class Myexception extends Exception	//extend keywords is used for interitance
{
      Myexception()
      {
          System.out.println("Exception thrown");
      }
}
 
 class exhandle
{
    public static void main(String args[])
    {
        int choice,a,mon;
      
        Scanner sc = new Scanner(System.in);
        bank b = new bank();
        
        b.accept();
        do
        {
            System.out.println("\n *** BANK SYSTEM *** ");
            System.out.println("");
            System.out.println("1. Display Customer details");
            System.out.println("2. Withdraw money");
            System.out.println("3. Deposit money");
            System.out.println("4. Exit");
            System.out.print("Enter Your choice : ");
            choice = sc.nextInt();
      
            switch(choice)
            {
                case 1:
                    b.display();
                    break;
                 
                case 2:
                    System.out.println("Enter the amount for transaction : ");
                    a = sc.nextInt();
                    b.transaction(a);
                    break;
                 
                case 3: System.out.println("Enter the amount to be deposited : ");
                    mon = sc.nextInt();
                    b.depo(mon);
                    break;
                 
                case 4: System.out.println("*** Thank You for using the Bank System ***");
                    break;
                
            }
            System.out.println("################################################");
        }while(choice!=4);
    }
}
     
     
