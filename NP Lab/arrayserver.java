import java.io.*;
import java.net.*;
class arrayserver {
	public static void main(String argv[]) throws Exception{
		int numbers;
		int N[] = new int[20];
		int i,large;
		ServerSocket welcomeSocket = new ServerSocket(3034);
		while(true) {
			Socket connectionSocket = welcomeSocket.accept();
			DataInputStream inFromClient = new DataInputStream(connectionSocket.getInputStream());
			DataOutputStream outToClient = new DataOutputStream(connectionSocket.getOutputStream());
			numbers = inFromClient.readInt();
			System.out.println("\nRecieved size : "+numbers);
			
			for(i = 0; i < numbers; i++) {
				N[i] = inFromClient.readInt();
				System.out.println("\nRecieved number : "+N[i]);
			}
			large = N[0];
			for(i=1;i<numbers;i++){
				if (N[i]>large)
					large = N[i];
			}
			System.out.println("\nLargest number : "+large);
			outToClient.writeInt(large);
		}	
	}
}

