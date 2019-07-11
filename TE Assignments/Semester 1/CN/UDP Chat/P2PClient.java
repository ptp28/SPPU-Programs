import java.io.*;
import java.net.*;

public class P2PClient
{
 public static void main(String args[]) throws IOException
 {
	 String message;
	 DatagramSocket DatagramSocket = new DatagramSocket();  
		  
	 byte[] receiveData = new byte[512];   
	 byte[] sendData  = new byte[512]; 
	 BufferedReader br = new BufferedReader(new InputStreamReader(System.in));  	
     	 InetAddress IPAddress = InetAddress.getByName("localhost"); 
	 
	 System.out.println("*** CLIENT READY ***");	  
	 while(true)
	 {
		System.out.print("Enter MESSAGE : ");	
		message = br.readLine();
		sendData = message.getBytes(); 
		DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length,IPAddress,3333); 
		DatagramSocket.send(sendPacket);
		if(message.equals("OVER&OUT"))
		{
			System.out.println("*** SYSTEM SHUT DOWN ***");	
			break;
		}	
		DatagramPacket receivePacket =new DatagramPacket(receiveData, receiveData.length); 
		DatagramSocket.receive(receivePacket); 
		message = new String(receivePacket.getData(), 0, receivePacket.getLength());
		System.out.println("Server Says : "+message);
		if(message.equals("OVER&OUT"))
		{
			System.out.println("*** SYSTEM SHUT DOWN ***");
			break;
		} 
	  }
			   
	}
}
