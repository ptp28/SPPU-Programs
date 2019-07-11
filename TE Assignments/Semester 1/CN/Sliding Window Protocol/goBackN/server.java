import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.ServerSocket;
import java.net.Socket;


public class server {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		int flag=0,count=0,check=0;
		
		ServerSocket server1 = new ServerSocket(5000);

		Socket client1 = new Socket();
		client1=server1.accept();
		System.out.println("Connection Established");
		DataInputStream din = new DataInputStream(client1.getInputStream());
		DataOutputStream dout= new DataOutputStream(client1.getOutputStream());
		
		int fr=din.read();
		boolean[] ch=new boolean[fr];
		int er_type=din.read();
		if(er_type==0)
		{
			System.out.println("Receiving Frames:");
			for(int i=0;i<fr;i++)
			{
				
				int a=din.read();
				System.out.println("Receive Frame:"+a);
				System.out.println("Sending Acknowledgement for frame:"+i);
				try
				{
					Thread.sleep(5000);
					
				}catch(Exception e)
				{
					
				}
				dout.write(1);
			}
		}
		else
		{
			
			for(int i=0;i<fr;i++)
			{
				if(i==2)
				{
					System.out.println("Received:");
					System.out.println("Sending Acknowledgement for Frame:"+i+" as :"+-1);
					flag=1;
					check=i;
					break;
				}
				else
				{
					int a=din.read();
					System.out.println("Receive Frame:"+a);
					System.out.println("Sending Acknowledgement for frame:"+i);
					try
					{
						Thread.sleep(5000);
						
					}catch(Exception e)
					{
						
					}
					dout.write(1);
					
				}
				
				}
			if(flag==1)
			{
				
				for(int i1=check;i1<fr;i1++)
				{
					ch[i1]=true;
					int a=din.read();
					System.out.println("Received Frame:"+i1);
					
				}
				System.out.println("Receiving Resended frames:");
				for(int i=0;i<fr;i++)
				{
					if(ch[i]==true)
					{
						int a1=din.read();
						System.out.println("Received Frame:"+a1);
						System.out.println("Sending Acknowledgement for frame:"+a1);
						try
						{
							Thread.sleep(5000);
						}catch(Exception e)
						{
							
						}
						dout.write(1);
					}
					else
					{
						i++;
					}
					
				}
			}
			
			
			
		}
		

	}

}
/*OUTPUT
Connection Established
Receive Frame:0
Sending Acknowledgement for frame:0
Receive Frame:1
Sending Acknowledgement for frame:1
Received:
Sending Acknowledgement for Frame:2 as :-1
Received Frame:2
Received Frame:3
Receiving Resended frames:
Received Frame:2
Sending Acknowledgement for frame:2
Received Frame:3
Sending Acknowledgement for frame:3
*/
