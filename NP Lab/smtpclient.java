import java.io.*;
import java.net.*;
public class chatroom2
{
 public static void main(String args[])throws IOException
 {
  String send,receive;
  Socket cs2=new Socket("localhost",3034);
  DataInputStream chatin=new DataInputStream(cs2.getInputStream());
  DataOutputStream chatout=new DataOutputStream(cs2.getOutputStream());
  DataInputStream keyin=new DataInputStream(System.in);
  while(true)
  {
   System.out.println("chatroom2:");
   send=keyin.readLine();
   chatout.writeBytes(send+"\n");
   if((receive=chatin.readLine())!=null)
   {
    System.out.println("chatroom1: "+receive);
   }
  }
 }
}
