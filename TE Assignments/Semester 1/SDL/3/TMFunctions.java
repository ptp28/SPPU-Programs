import java.util.*;
import java.net.*;
import java.io.*;
import java.sql.*;

class TMFunctions
{	
	Scanner sc = new Scanner(System.in);

	TreeMap<Integer,Database> hm=new TreeMap<Integer,Database>(); 
	TreeMap<Integer,Database> hmTemp=new TreeMap<Integer,Database>(); 
	static int rollNo=0;
	
	public void addData(DataInputStream din, DataOutputStream dout) throws Exception
	{
		String name;
		float percentage;
		int num;
		
		dout.writeUTF("NUMBER OF ENTRIES : ");
		dout.writeUTF("read");
		num = Integer.parseInt(din.readUTF());
		
		Class.forName("com.mysql.jdbc.Driver");
		Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/student1","root","root");
		Statement stmt=con.createStatement(); 

		hmTemp.clear();
		for(int i = 0 ; i < num ; i++)
		{
			try
			{
				rollNo++;
				//dout.writeUTF("Enter NAME : ");
				//dout.writeUTF("read");
				//name = din.readUTF();
				dout.writeUTF("Enter PERCENTAGE : ");
				dout.writeUTF("read");
				percentage = Float.parseFloat(din.readUTF());
				Database d = new Database(rollNo,percentage);
				hmTemp.put(rollNo,d);
				stmt.executeUpdate("insert into student_data values("+rollNo+","+percentage+");");
			}
			catch(InputMismatchException e)
			{
				dout.writeUTF("WRONG DATATYPE ENTERED");
			}
		}
		hm.putAll(hmTemp);
	}
	
	public void getData(DataInputStream din, DataOutputStream dout) throws Exception
	{
		dout.writeUTF("\nTHE DATA IN THE TREEMAP IS\n");
		Class.forName("com.mysql.jdbc.Driver");
		Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/student1","root","root");
		Statement stmt=con.createStatement(); 
		ResultSet rs=stmt.executeQuery("select * from student_data;");
		while(rs.next())
		{  
			int r = rs.getInt(1);
			Database dd = new Database(r,rs.getFloat(2));
			dd.show(din, dout);
		}
	}
	
	public void removeData(DataInputStream din, DataOutputStream dout) throws Exception
	{
		
		int key=0,choice,sIndex=0,lIndex=1,flag;
		Database removed = new Database();
		dout.writeUTF("1. Remove SINGLE entry\n2. Remove MULTIPLE entries\nEnter your choice : ");
		dout.writeUTF("read");
		choice = Integer.parseInt(din.readUTF());
		
		switch(choice)
		{
		case 1:
			dout.writeUTF("Enter KEY : ");
			do
			{
				try
				{
					dout.writeUTF("read");
					key = Integer.parseInt(din.readUTF());
					flag=0;
				}
				catch(InputMismatchException e)
				{
					dout.writeUTF("WRONG DATATYPE ENTERED");
					flag=1;
				}
			}while(flag==1);
			hmTemp.clear();
			
			removed = hm.remove(key);
			
			hmTemp.put(key,removed);
			break;
		case 2:
			do
			{
				try
				{
					dout.writeUTF("DELETE from ROLL NUMBER : ");
					dout.writeUTF("read");
					sIndex = Integer.parseInt(din.readUTF());
					dout.writeUTF("DELETE till ROLL NUMBER : ");
					dout.writeUTF("read");
					lIndex = Integer.parseInt(din.readUTF());
					flag=0;
				}
				catch(InputMismatchException e)
				{
					dout.writeUTF("WRONG DATATYPE ENTERED");
					flag = 1;
				}
				hmTemp.clear();
			}while(flag==1);
			
			for(int i = sIndex ;i < lIndex ; i++ )
			{
				removed = (Database)hm.remove(i);
				removed.show(din, dout);
				hmTemp.put(i, removed);
			}
			break;
		}
		dout.writeUTF("\n THE FOLLOWING DATA WILL BE REMOVED PERMANENTLY \n");
		for(Map.Entry<Integer,Database> mm : hmTemp.entrySet())
		{  
			int r = mm.getKey();
			Database dd = mm.getValue();
			dd.show(din, dout);
		}
		dout.writeUTF("DO YOU WANT TO CONTINUE (y/N) : ");
		dout.writeUTF("read");
		char ch = din.readUTF().charAt(0);
		if(ch=='y')
		{
			hmTemp.clear();
		}
		else
		{
			hm.putAll(hmTemp);
		}	
	}
	
	public void searchData(DataInputStream din, DataOutputStream dout) throws Exception
	{
		int key=0,flag;
		dout.writeUTF("Enter KEY : ");
		do
		{
			try
			{
				dout.writeUTF("read");
				key = Integer.parseInt(din.readUTF());
				flag=0;
			}
			catch(InputMismatchException e)
			{
				dout.writeUTF("WRONG DATATYPE ENTERED");
				flag=1;
			}
		}while(flag==1);
		if(hm.containsKey(key))
		{
			dout.writeUTF("THE KEY IS PRESENT");
		}
		else
		{
			dout.writeUTF("THE KEY IS NOT PRESENT");
		}
	}
	
	public void getSize(DataInputStream din, DataOutputStream dout) throws Exception
	{
		dout.writeUTF("The SIZE of the TreeMap is : " + hm.size());
	}
}
