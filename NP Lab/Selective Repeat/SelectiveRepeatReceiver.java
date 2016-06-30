import java.io.*;
import java.net.*;
public class SelectiveRepeatReceiver {
 	public static void main(String args[])throws IOException {
  		String send,receive;
  		int windowSize, condition, frame, flag = 0;
  		int Data[] = new int[16];
  		ServerSocket ss = new ServerSocket(3030);
  		Socket cs1 = ss.accept();
  		DataInputStream chatin = new DataInputStream(cs1.getInputStream());
  		DataOutputStream chatout = new DataOutputStream(cs1.getOutputStream());
  		DataInputStream keyin = new DataInputStream(System.in);
  		while(true) {
  		     windowSize = Integer.parseInt(chatin.readLine());
   			condition = Integer.parseInt(chatin.readLine());
   			frame = Integer.parseInt(chatin.readLine());
   			Data[frame] = Integer.parseInt(chatin.readLine());
			if(condition == 1) {
				System.out.println("\n *Received frame "+frame%windowSize+" with Data "+Data[frame]);
				if(frame == flag) {
					System.out.println("\n +Accepeted frame "+frame%windowSize+" with Data "+Data[frame]);
					chatout.writeBytes(frame+1+"\n");
   					flag++;
   				}
   				else {
   					System.out.println("\n -Rejected frame "+frame%windowSize+" with Data "+Data[frame]);
   					chatout.writeBytes("-1\n");
   				}
   			}
   			
  		}
 	}
}


