import java.io.*;
import java.net.*;

class MCServer
{
    public static void main(String args[]) throws Exception
    {
        ServerSocket ss = new ServerSocket(1234);
        Socket conn = null;
        Responder h = new Responder();
        while(true)
        {
            conn = ss.accept();
            Thread t = new Thread(new MyServer(h,conn));
            t.start();
        }
    }
}

class MyServer implements Runnable
{
    Responder h;
    Socket conn;
    MyServer(Responder h , Socket conn)
    {
        this.h = h;
        this.conn = conn;
    }
    
    public void run()
    {
        try
        {
            while(h.methodResponder(conn))
            {
                try
                {
                    Thread.sleep(5000);
                }
                catch(Exception e)
                {
                    
                }
                try
                {
                    conn.close();
                }
                catch(Exception e)
                {
                    
                }
            }
        }
        catch(Exception e)
        {
            
        }
    }
}

class Responder
{
    public boolean methodResponder(Socket conn) throws Exception
    {
        BufferedReader fromUser = new BufferedReader(new InputStreamReader(System.in));
        DataOutputStream dos = new DataOutputStream(conn.getOutputStream());
        BufferedReader fromClient = new BufferedReader(new InputStreamReader(conn.getInputStream()));
        String message;
        try
        {
            do
            {
                message = fromClient.readLine();
                System.out.println("CLIENT : "+message);
                System.out.print("Enter message : ");
                message = fromUser.readLine();
                dos.writeBytes(message+"\n");
            }while(!message.equals("EXIT"));
        }
        catch(Exception e)
        {
            return false;
        }
        return true;
    }
}
