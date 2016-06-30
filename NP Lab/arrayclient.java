import java.io.*;
import java.net.*;
class arrayclient {
	public static void main(String argv[]) throws Exception{
		int numbers;
		int N[] = new int[10];
		int largest;
		DataInputStream inFromUser = new DataInputStream(System.in);
		Socket clientSocket = new Socket("localhost",3034);
		DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());
		DataInputStream inFromServer = new DataInputStream(clientSocket.getInputStream());
		System.out.println("\n Enter the number of elements: \n");
		numbers = Integer.parseInt(inFromUser.readLine());
		outToServer.writeInt(numbers);
		System.out.println("\n Enter the numbers: \n");
		for(int i = 0; i < numbers; i++) {
    		N[i] = Integer.parseInt(inFromUser.readLine());
    		outToServer.writeInt(N[i]);
    	}	
		largest = inFromServer.readInt();
		//Integer.toString(i);
		System.out.println("\n FROM SERVER -> Largest is " + largest);
		clientSocket.close();
	}
}
