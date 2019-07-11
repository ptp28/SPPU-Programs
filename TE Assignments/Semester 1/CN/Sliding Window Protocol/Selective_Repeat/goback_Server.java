import java.io.*;
import java.net.*;
import java.util.*;


class goback_Server
 {
  public static void main(String args[]) throws Exception
   {
   	int flag = 0, cnt = 0, check = 0;
    ServerSocket socket = new ServerSocket(6000);
    Socket sock = new Socket();
    sock = socket.accept();
    System.out.println("Connecton established Successfully...");

    DataInputStream din = new DataInputStream(sock.getInputStream());
    DataOutputStream dout = new DataOutputStream(sock.getOutputStream());
    int frames = din.read();
    boolean buf[] = new boolean[frames];
    int choice = din.read();
    if(choice == 1)
    {
    	System.out.println("Receiving the Frames...");
    	for(int i=0;i<frames;i++)
    	{
    		int r = din.read();
    		System.out.println("Receiving Frame "+r);
    		System.out.println("Sending Acknowledgement for the frame "+i);
    		try
    		 {
    		 	Thread.sleep(5000);
    		 }
    		 catch(Exception e)
    		 {
                System.out.println(""+e);
    		 }
    		 dout.write(1);
    	}
    }
    
    else
    {
    	for(int i=0;i<frames;i++)
    	{
    		if(i == 3)
    		{
    			System.out.println("Received Damaged Frame...");
    			System.out.println("Sending Acknowledgement for frame "+i+"as "+-1);
    			flag = 1;
    			check = i;
    			break;
    		}
    		else
    		{
    			int r = din.read();
    			System.out.println("Received Frame "+r);
    			System.out.println("Sending Acknowledgement for Frame "+i);
    			try
    			{
    				Thread.sleep(5000);
    			}
    			catch(Exception e)
    			{
    				System.out.println(""+e);
    			}
    			dout.write(1);
    		}
    	}

    	if(flag == 1)
    	{
    		for(int ii=check;ii<frames;ii++)
    		{
    		   buf[ii]=true;
		   int a=din.read();
		   System.out.println("Received Frame:"+ii);
		}
 
            System.out.println("Receiving Resended frames:");
//	    for(int i=0;i<frames;i++)
	      {
//		if(buf[i]==true)
		 {
		   int s=din.read();
		   System.out.println("Received Frame:"+s);
		   System.out.println("Sending Acknowledgement for frame:"+s);
		   try
		    {
			Thread.sleep(5000);
		    }
		    catch(Exception e)
		    {
			System.out.println(""+e);				
		    }
		  dout.write(1);
		 }
	//	else
		 {
	//	   i++;
		 }
					
	      }
	}
			
     }
   }
}

/*OUTPUT
Connecton established Successfully...
Receiving the Frames...
Receiving Frame 0
Sending Acknowledgement for the frame 0
Receiving Frame 1
Sending Acknowledgement for the frame 1
Receiving Frame 2
Sending Acknowledgement for the frame 2

*/



