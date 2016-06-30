import java.io.*;
import java.net.*;
public class chatroom1
{
 public static void main(String args[])throws IOException
 {
  String send,receive;
  ServerSocket ss=new ServerSocket(3034);
  Socket cs1= ss.accept();
  DataInputStream chatin = new DataInputStream(cs1.getInputStream());
  DataOutputStream chatout = new DataOutputStream(cs1.getOutputStream());
  DataInputStream keyin = new DataInputStream(System.in);
  while(true)
  {
   if((receive=chatin.readLine())!=null)
   {
    System.out.println("chatroom2: "+receive);
   }
   System.out.println("chatroom1:");
   send=keyin.readLine();
   chatout.writeBytes(send+"\n");
  }
 }
}
