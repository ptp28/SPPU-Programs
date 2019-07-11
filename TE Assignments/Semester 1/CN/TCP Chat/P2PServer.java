import java.io.*;
import java.net.*;

class P2PServer
{
    public static void main(String args[]) throws Exception
    {
        BufferedReader fromUser = new BufferedReader(new InputStreamReader(System.in));
        ServerSocket ss = new ServerSocket(1234);
        Socket conn = ss.accept();
        DataOutputStream dos = new DataOutputStream(conn.getOutputStream());
        BufferedReader fromClient = new BufferedReader(new InputStreamReader(conn.getInputStream()));
        String message;
        
        do
        {
            message = fromClient.readLine();
            System.out.println("CLIENT : "+message);
            System.out.print("Enter message : ");
            message = fromUser.readLine();
            dos.writeBytes(message+"\n");
        }while(!message.equals("EXIT"));
    }
}
