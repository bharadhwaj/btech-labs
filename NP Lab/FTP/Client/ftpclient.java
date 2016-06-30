import java.io.*;
import java.net.*;
import java.nio.*;
import java.nio.channel.*;


class TCPClient {
public static void main(String argv[]) throws Exception
{
String filename,username,password,filedata;
FileOutputStream fout;
FileChannel fchan;
ByteBuffer mbuf;
long fsize;
bytes contentinbytes[];

String modifiedSentence,buffer;
BufferedReader inFromUser =new BufferedReader(new InputStreamReader(System.in));
Socket clientSocket = new Socket("localhost", 5333);
DataOutputStream outToServer =new DataOutputStream(clientSocket.getOutputStream());
BufferedReader inFromServer =new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

System.out.println("enter the username");
username=inFromUser.readLine();
System.out.println("enter the password");
password=inFromUser.readLine();
outToServer.writeBytes(username + '\n');
outToServer.writeBytes(password + '\n');


System.out.println("enter the file name");

filename = inFromUser.readLine();
//outToServer.writeBytes(filename + '\n');
modifiedSentence = inFromServer.readLine();

//if(modifiedsentence==authentication )
System.out.println(" " + modifiedSentence);
if(modifiedSentence=="authentication successful")
{
buffer=inFromServer.read();
contentinbytes=buffer.getBytes();
//filedata=contentinbytes.toString();
OutputStream f1=new FileOutputStream("username.txt");
f1.write(contentinbytes)
f1.close();
}
clientSocket.close();
}
}

