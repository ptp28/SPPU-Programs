import java.io.*;
import java.net.*;

class P2PClient
{
    public static void main(String args[]) throws Exception
    {
        BufferedReader fromUser = new BufferedReader(new InputStreamReader(System.in));
        Socket conn = new Socket("127.0.0.1",1234);
        DataOutputStream dos = new DataOutputStream(conn.getOutputStream());
        BufferedReader fromServer = new BufferedReader(new InputStreamReader(conn.getInputStream()));
        String message;
        
        do
        {
            System.out.print("Enter message : ");
            message = fromUser.readLine();
            dos.writeBytes(message+"\n");
            message = fromServer.readLine();
            System.out.println("SERVER : "+message);
        }while(!message.equals("EXIT"));
    }
}

