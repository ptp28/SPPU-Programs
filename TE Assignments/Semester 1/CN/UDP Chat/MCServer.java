import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.util.Scanner;

public class MCServer {

	public static void main(String[] args) throws IOException {
		
		DatagramSocket sc = new DatagramSocket(3333);
		
		byte[] receiveData = new byte[512]; 
		byte[] sendData  = new byte[512];
		int port;
		
		Scanner s = new Scanner(System.in);
		
		while(true)
		{
			
			DatagramPacket dp = new DatagramPacket( receiveData,  receiveData.length);
			sc.receive(dp);
			String msg = new String(dp.getData(),0,dp.getLength());
			System.out.println("Client says : " + msg);
			if(msg.equals("OVER&OUT"))
			{
				System.out.println("*** SYSTEM SHUT DOWN ***");
				break;
			}
			
			InetAddress ip = dp.getAddress();
			port = dp.getPort();
			
			System.out.println("Enter MESSAGE : ");
			msg = s.nextLine();
			sendData  = msg.getBytes();
			DatagramPacket snd = new DatagramPacket(sendData ,sendData.length, ip , port);
			sc.send(snd);
			if(msg.equals("OVER&OUT"))
			{
				System.out.println("*** SYSTEM SHUT DOWN ***");
				break;
			
			}
		
		}
		

	}

}
