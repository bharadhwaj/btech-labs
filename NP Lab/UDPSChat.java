import java.io.*;
import java.net.*;
class UDPSChat {
    public static void main(String args[]) throws Exception {
        BufferedReader inFromUser =new BufferedReader(new InputStreamReader(System.in));
        DatagramSocket serverSocket = new DatagramSocket(9875);
        byte[] receiveData = new byte[1024];
        byte[] sendData = new byte[1024];
        String sentence;
        while(true) {


            DatagramPacket receivePacket =new DatagramPacket(receiveData, receiveData.length);
            serverSocket.receive(receivePacket);
            sentence = new String(receivePacket.getData());
            InetAddress IPAddress = receivePacket.getAddress();
            int port = receivePacket.getPort();
            System.out.println("From client:"+sentence);


            sentence = inFromUser.readLine();
            sendData = sentence.getBytes();
            DatagramPacket sendPacket =new DatagramPacket(sendData, sendData.length, IPAddress,port);
            serverSocket.send(sendPacket);

//DatagramPacket sendPacket =new DatagramPacket(sendData, sendData.length, IPAddress,port);
//serverSocket.send(sendPacket);
        }
    }
}

