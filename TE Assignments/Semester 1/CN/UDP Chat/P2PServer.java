import java.io.*;
import java.net.*;

public class P2PServer
{
  public static void main(String args[]) throws IOException 
  {
	 DatagramSocket datagramSocket = new DatagramSocket(3333);  
		  
	 byte[] receiveData = new byte[512]; 
	 byte[] sendData  = new byte[512];
	 String clientString , serverString;
	 BufferedReader br = new BufferedReader(new InputStreamReader(System.in));   
	 System.out.println("*** SERVER READY ***");
		
	 while(true) 
	 { 
	 	DatagramPacket receivePacket =new DatagramPacket(receiveData, receiveData.length); 
	  	datagramSocket.receive(receivePacket); 
	  	clientString = new String(receivePacket.getData(), 0, receivePacket.getLength()); 
	  	System.out.println("Client Says: "+clientString);
	  	if(clientString.equals("OVER&OUT")) 
			break;
	  	System.out.print("Enter MESSAGE :");
	  	serverString = br.readLine();
	  	InetAddress IPAddress = receivePacket.getAddress(); 
	  	int port = receivePacket.getPort(); 
	  	sendData = serverString.getBytes(); 
	  	DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress,port); 
	  	datagramSocket.send(sendPacket);
		if(serverString.equals("OVER&OUT")) 
			break; 
	} 	
    	datagramSocket.close();
    	System.out.println("*** SYSTEM SHUT DOWN ***");
  }
}

