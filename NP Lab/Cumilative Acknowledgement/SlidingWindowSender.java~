import java.io.*;
import java.net.*;
import java.util.*;
import java.lang.*;
public class SlidingWindowSender {
	public static void main(String args[]) throws IOException {
  		int windowSize, flag = 0, condition, f, ack, i;
  		int Data[] = new int[16];
  		for(i = 0; i < 16; i++)
  			Data[i] = i;
  		System.out.println("\n Enter the window size: ");	
  		Scanner in = new Scanner(System.in);
  		windowSize = in.nextInt();
  		Socket cs2 = new Socket("localhost",3030);
  		DataInputStream chatin = new DataInputStream(cs2.getInputStream());
  		DataOutputStream chatout = new DataOutputStream(cs2.getOutputStream());
  		DataInputStream keyin = new DataInputStream(System.in);
  		while(true) {
  			f = flag;
	  		for(i = flag; i < flag+windowSize && i < 7; i++) {
   				Random rand = new Random();
				condition = Math.abs(rand.nextInt())%2;
				chatout.writeBytes(windowSize+"\n");
				chatout.writeBytes(condition+"\n");
   				chatout.writeBytes(i+"\n");
   				chatout.writeBytes(Data[i]+"\n");
   				System.out.println("\n =Sent frame "+ i%windowSize +" with data "+Data[i]);
			}				
   			ack = Integer.parseInt(chatin.readLine());
   			if(ack == f+1) {
   				System.out.println("\n #Received Acknowledgement "+ ack%windowSize);
   				flag++;
  			}
  			else if(ack == -1) {
  			     System.out.println("\n #Resending the Frame "+ (i+1)%windowSize);
   				i--;
  			}
  		}
 	}
}
