import java.util.*;
import java.io.*;
import java.net.*;

class goback_Client
 {
  public static void main(String args[]) throws Exception
   {
    Socket sock = new Socket("localhost",6000);
    DataInputStream din = new DataInputStream(sock.getInputStream());
    DataOutputStream dout = new DataOutputStream(sock.getOutputStream());
    Scanner sc = new Scanner(System.in);
    int damaged = 0,flag = 0;
    int frames;
    System.out.println("Enter the number of Frames ");
    frames = sc.nextInt();
    dout.write(frames);
    boolean buf[] = new boolean[frames];
    System.out.println("1. Frames without Error ");
    System.out.println("2. Frames with Error ");
    System.out.println("Enter your Choice");
    int ch = sc.nextInt();
    dout.write(ch);

    if(ch == 1)
    {
    	System.out.println("Sending Frames....");
    	for(int i=0;i<frames;i++)
    	{
    		System.out.println("Sending Frame "+i);
    		dout.write(i);
    		System.out.println("Waiting for Acknowledgement....");
    		int a = din.read();
    		System.out.println("Acknowledgement of Frame "+ i + "as :"+1);
    	}
    }

    else
    {
    	for(int i=0;i<frames;i++)
    	{
    		if(i == 3)
    		{
    			System.out.println("Sending Frame.."+i);
    			
    			System.out.println("Acknowledgement of Frame "+i+"as "+-1);
    			
    			damaged = i;
    			flag = 1;
    			break;
    		}

    		else
    		{
    		  System.out.println("Sending Frame "+i);
    		  dout.write(i);
    		  System.out.println("Waiting for Acknowledgement....");
    		  int a = din.read();
    		  System.out.println("Acknowledgement of Frame "+ i + "as :"+1);	
    		}
    	}

    	if(flag == 1)
    	{
    		for(int i=damaged;i<frames;i++)
    		{
    			buf[i] = true;
    			dout.write(i);
    			System.out.println("Sending Frame.."+i);
    		}
//    		for(int i=0;i<frames;i++)
    		{
    			System.out.println("Sending Frames Without Error...");
//    			if(buf[i] == true)
    			{
    				System.out.println("Resending the Frame..."+damaged);
    				dout.write(damaged);
    				System.out.println("Now Waiting for Acknowledgement...");
    				int a1 = din.read();
    				System.out.println("Acknowledgement for frame "+damaged+"as "+1);
    			}
  //  			else
    			{
    //				i++;
    			}
    		}
    	}
    }

/*OUTPUT
Enter the number of Frames 
3
1. Frames without Error 
2. Frames with Error 
Enter your Choice
1
Sending Frames....
Sending Frame 0
Waiting for Acknowledgement....
Acknowledgement of Frame 0as :1
Sending Frame 1
Waiting for Acknowledgement....
Acknowledgement of Frame 1as :1
Sending Frame 2
Waiting for Acknowledgement....
Acknowledgement of Frame 2as :1
*/
  }
}

    

