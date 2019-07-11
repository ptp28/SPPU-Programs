import java.net.*;  
import java.io.*;  
import java.util.*;

public class Database 
{
	String name;
	int rollNo;
	float percentage;
	Database()
	{
		rollNo = 0;
		percentage = 0.0f;
	}
	Database(int rollNo,float percentage)
	{
		//this.name = name;
		this.rollNo = rollNo;
		this.percentage = percentage;
	}
	
	void show(DataInputStream din, DataOutputStream dout) throws Exception
	{
		dout.writeUTF("ROLL NUMBER : " + rollNo);
		dout.writeUTF("NAME : " + name);
		dout.writeUTF("PERCENTAGE : " + percentage);
	}
}
