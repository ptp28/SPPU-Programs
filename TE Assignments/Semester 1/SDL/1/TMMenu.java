import java.util.*;

public class TMMenu
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		TMFunctions tm = new TMFunctions();
		int choice;
		
		do
		{
			System.out.println("*** Tree Map ***");
			System.out.print("\n1. ADD Data to TreeMap\n2. DISPLAY Data from TreeMap\n3. DELETE Data from TreeMap\n4. SEARCH Data from TreeMap\n5. Get SIZE of TreeMap\n0. EXIT\nENTER YOUR CHOICE : ");
			choice = sc.nextInt();
			switch(choice)
			{
			case 1 :
				tm.addData();
				break;
			case 2 :
				tm.getData();
				break;
			case 3 :
				tm.removeData();
				break;
			case 4 :
				tm.searchData();
				break;
			case 5 :
				tm.getSize();
				break;
			case 6 : 
				break;
			default:
				System.out.println("!!! WRONG CHOICE ENTERED !!!");	
			}
		}while(choice!=0);
	}
}
