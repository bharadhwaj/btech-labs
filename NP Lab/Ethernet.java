import java.util.*;

class Bus {
	boolean BUSY = false;
	public synchronized int getBus(int n1, int n2, int ptime) {
		int flag = 0;
		Random rn = new Random();
		int ntime = Math.abs(rn.nextInt() % 20);
		if(!BUSY) {
			if(ptime < ntime) {
				BUSY = true;
				System.out.println("\n "+n1+" & "+n2+" is using the bus.");
				flag = 1;
			}
			else {
				System.out.println("\n Collision is detected between "+n1+" & "+n2);
				flag = 0;
			}
		}
		else if(BUSY) {
			System.out.println("\n "+n1+" & "+n2+" needs to communicate but bus is busy.");
			flag = 0;
		}
		if(flag == 1)
			return 1;
		else
			return 0;
	}
	public synchronized void releaseBus(int res, int n1, int n2) {
		if(res == 1) {
			System.out.println("\n "+n1+" & "+n2+" released the bus.");
			BUSY = false;
		}
		notifyAll();
	} 
}

class Nodes implements Runnable {
	Bus bus;
	int num1, num2, ptime, res;
	Thread t;
	Nodes(Bus bus, int num1, int num2, int ptime) {
 		this.bus=bus;
 		this.num1 = num1;
 		this.num2 = num2;
 		this.ptime = ptime;
 		t = new Thread(this,"Nodes");
 		t.start();
 	}

 	public void run() {
		res = bus.getBus(num1, num2, ptime);
		try {
			Thread.sleep(150);
		} catch(Exception e){
				System.out.println("\n Error: "+e);
		}
		bus.releaseBus(res, num1, num2);
 	}
}

class Ethernet {
	public static void main(String args[]) {
		Scanner s = new Scanner(System.in);
		System.out.println("\n Enter the number of nodes: ");
		int nodes = s.nextInt();
		System.out.println("\n Enter the propagation time: ");
		int ptime = s.nextInt();
		Bus bus = new Bus();
		Nodes[] N = new Nodes[20];
		int i;
		int n1, n2;
		Random rn = new Random();
		for(i = 0; i < 10; i++) {
			n1 = Math.abs(rn.nextInt() % nodes);
			n2 = Math.abs(rn.nextInt() % nodes);
			if(n1 != n2) 
				N[i] = new Nodes(bus, n1+1, n2+1, ptime);
			else {
				n1++;
				N[i] = new Nodes(bus, n1+1, n2+1, ptime);
			}
			try {
			Thread.sleep(100);
			} catch(Exception e){
				System.out.println("\n Error: "+e);
			}			
		}
	}	
}

