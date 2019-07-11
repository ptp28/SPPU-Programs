import java.net.*;  
import java.io.*;  
import java.util.*;

public class TMMenu
{
	static int serverPort=3306;

	public static void main(String args[]) throws Exception
	{
		ServerSocket ss=new ServerSocket(serverPort);
		Socket s=ss.accept();
		TMFunctions tm = new TMFunctions();
		Scanner sc = new Scanner(System.in);
		DataInputStream din=new DataInputStream(s.getInputStream());
		DataOutputStream dout=new DataOutputStream(s.getOutputStream());
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));	
		int choice;
		
		do
		{
			dout.writeUTF("*** Tree Map ***");
			dout.writeUTF("\n1. ADD Data to TreeMap\n2. DISPLAY Data from TreeMap\n3. DELETE Data from TreeMap\n4. SEARCH Data from TreeMap\n5. Get SIZE of TreeMap\n0. EXIT\nENTER YOUR CHOICE : ");
			dout.writeUTF("read");
			choice = Integer.parseInt(din.readUTF());
			switch(choice)
			{
			case 1 :
				tm.addData(din, dout);
				break;
			case 2 :
				tm.getData(din, dout);
				break;
			case 3 :
				tm.removeData(din, dout);
				break;
			case 4 :
				tm.searchData(din, dout);
				break;
			case 5 :
				tm.getSize(din, dout);
				break;
			default:
				dout.writeUTF("!!! WRONG CHOICE ENTERED !!!");	
			}
		}while(choice!=0);
	}
}