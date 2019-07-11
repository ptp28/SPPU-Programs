import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.*;
public class client {

	/**
	 * @param args
	 **/
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		int flag=0,corrupt=0;
		
		Scanner sc =new Scanner(System.in);
		Socket client1 = new Socket("localhost",5000);
		ServerSocket s1=new ServerSocket();
		DataInputStream din = new DataInputStream(client1.getInputStream());
		DataOutputStream dout= new DataOutputStream(client1.getOutputStream());
		System.out.println("Enter no of frames:");
		int f=sc.nextInt();
		dout.write(f);
		boolean[] ch=new boolean[f];
		System.out.println("enter type of transfer:");
		System.out.println("1:Frames with error");
		System.out.println("0:Frames without error");
		int error_type=sc.nextInt();
		dout.write(error_type);
		if(error_type==0)
		{
			System.out.println("... Sending Frames ... ");
			for(int i=0;i<f;i++)
			{
				System.out.println("Sending Frame:"+i);
				dout.write(i);
				System.out.println("Waiting for Acknowledgement:");
				int ack=din.read();
				System.out.println("Acknowledgement for Frame:"+i+" as :"+1);
				
			}
		}
		else
		{
			///// Corrupted Frame Transfer
			
			for(int i=0;i<f;i++)
			{
				if(i==2)
				{
					System.out.println("Sending Frame:"+i);
					System.out.println("Acknowledgement for Frame:"+i+" as :"+-1);
				    corrupt=i;
					flag=1;
					break;
				}
				else
				{
					System.out.println("Sending Frame:"+i);
					dout.write(i);
					System.out.println("Waiting for Acknowledgement:");
					int ack=din.read();
					System.out.println("Acknowledgement for Frame:"+i+" as :"+1);
				}
				
			}
			if(flag==1)
			{
				for(int i=corrupt;i<f;i++)
				{
					ch[i]=true;
					dout.write(i);
					System.out.println("Sending Frame:"+i);
				}
				for(int i=0;i<f;i++)
				{
		System.out.println("0:Frames without error");
					if(ch[i]==true)
					{
						System.out.println("Resending Frame:"+i);
						dout.write(i);
						System.out.println("Waiting For Acknowledgement:");
						int ack1=din.read();
		//boolean[] ch1=new boolean[f];
						System.out.println("Acknowledgement for Frame:"+i+" as :"+1);		
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
Enter no of frames:
4
enter type of transfer:
1:Frames with error
0:Frames without error
1
Sending Frame:0
Waiting for Acknowledgement:
Acknowledgement for Frame:0 as :1
Sending Frame:1
Waiting for Acknowledgement:
Acknowledgement for Frame:1 as :1
Sending Frame:2
Acknowledgement for Frame:2 as :-1
Sending Frame:2
Sending Frame:3
0:Frames without error
0:Frames without error
Resending Frame:2
Waiting For Acknowledgement:
Acknowledgement for Frame:2 as :1
0:Frames without error
Resending Frame:3
Waiting For Acknowledgement:
Acknowledgement for Frame:3 as :1
*/
