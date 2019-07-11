import java.util.*;
import java.net.*;
import java.io.*;
import java.sql.*;

public class TMMenu
{
	static int serverPort=3333;
	static int nn=0;

	public static void main(String args[]) throws Exception
	{
		ServerSocket ss=new ServerSocket(serverPort);
		Responder h=new Responder();
		
		while(true)
		{
			Socket s=ss.accept();
			System.out.println("Client received 1");			 
			Thread t=new Thread(new MyServer(h,s,nn));
			t.start();	
		}
	}
}


class MyServer implements Runnable
{
	Responder h;
	Socket connectionSocket ;
	int nn=0;
	public MyServer(Responder h,Socket connectionSocket,int nn)
	{
		this.h=h;
		this.connectionSocket=connectionSocket;
		this.nn=nn; 
	}
	public void run()
	{
		try
		{
			while(h.responderMethod(connectionSocket,nn))
		 	{
		 		try
		 		{
		 			Thread.sleep(5000);
		 		}
		 		catch(Exception e)
		 		{
				}
		 		try
		 		{
		 			connectionSocket.close();
		 		}
		 		catch(Exception e)
		 		{
		 		}
		 		
		 	}		
		}
		catch(Exception e)
		{
		}
	 }
}

class Responder
{
	public boolean responderMethod(Socket s,int nn) throws Exception
	{
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
		return true;
	}
}
