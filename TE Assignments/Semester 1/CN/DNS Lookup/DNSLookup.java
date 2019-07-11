import java.util.*;
import java.net.*;

class DNSLookup
{
    public static void main(String args[]) throws Exception
    {
        int choice;
        Scanner sc = new Scanner(System.in);
        InetAddress ina;
        do
        {
            System.out.println("*** MAIN MENU ***");
            System.out.println("\n1. Search by IP Address");
            System.out.println("2. Search by website name");
            System.out.println("3. Exit");
            System.out.print("Enter your choice : ");
            choice = sc.nextInt();
            switch(choice)
            {
                case 1 :
                    System.out.print("\nEnter an IP address : ");
                    String ip = sc.next();
                    ina = InetAddress.getByName(ip);
                    System.out.print("The host name is : ");
                    System.out.println(ina.getHostName());
                    System.out.println("");
                    break;
                case 2 :
                    System.out.print("\nEnter a website address : ");
                    String name = sc.next();
                    ina = InetAddress.getByName(name);
                    System.out.print("The IP address is : ");
                    System.out.println(ina.getHostAddress());
                    System.out.println("");
                    break;
                case 3 :
                    break;
            }
        }while(choice!=3);
    }
}
