import java.io.*;
import java.net.*;
import java.nio.*;
import java.nio.channel.*;

class TCPServer {
public static void main(String argv[]) throws Exception
{
int flag;
String str,strs,user,pass;
FileInputStream fin;
FileChannel fchan;
ByteBuffer mbuf;
long fsize;



String clientSentence;
String capitalizedSentence;
ServerSocket welcomeSocket = new ServerSocket(5333);
while(true) {
Socket connectionSocket = welcomeSocket.accept();
BufferedReader inFromClient =new BufferedReader(new InputStreamReader(connectionSocket.getInputStream()));
DataOutputStream outToClient =new DataOutputStream(connectionSocket.getOutputStream());
fin=new FileInputStream("username.text");
fchan=fin.getChannel();
fsize=fchan.size();
mbuf=ByteBuffer.allocate((int)fsize);
fchan.read(mbuf);
mbuf.rewind();
str=mbuf.toString();


user = inFromClient.readLine();
pass= inFromClient.readLine();
strs=user+'$'+pass;
flag=str.indexOf(strs);
if(flag==-1)
{
outToClient.writeBytes("authentication failed"+'\n');
//System.out.println("client has send "+clientSentence);
//capitalizedSentence = clientSentence.toUpperCase() + '\n';
//outToClient.writeBytes(capitalizedSentence);
}
else
{
outToClient.writeBytes("authentication successful"+'\n');
outToClient.writeBytes(str+'\n');
}
}
}
}
