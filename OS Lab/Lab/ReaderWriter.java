// An implementation of a producer and consumer.

class ReadWrite {
	int n;
	boolean valueSet = false;
	synchronized void get() {
		if(!valueSet)
		try {
			wait();
		}
		catch(InterruptedException e) {
			System.out.println("Error: InterruptedException caught.");
		}
		valueSet = false;
		System.out.println("Read: " + n);
		try{
			Thread.sleep(1000);
		}
		catch(Exception e){
			System.out.println("Error: " + e);
		}
		notify();
		//return n;
	}
	synchronized void put(int n) {
		if(valueSet)
		try {
			wait();
		}
		catch(InterruptedException e) {
			System.out.println("Error: InterruptedException caught.");
		}
		this.n = n;
		System.out.println("Wrote: " + n);
		valueSet = true;
		try{
			Thread.sleep(100);
		}
		catch(Exception e){
			System.out.println("Error: " + e);
		}
		notify();
	}
}

class Producer implements Runnable {
	ReadWrite q;
	Producer(ReadWrite q) {
		this.q = q;
		new Thread(this, "Producer").start();
	}
	public void run() {
		int i = 0;
		while(i <= 5) {
			q.put(i++);
		}
	}
}

class Consumer implements Runnable {
	ReadWrite q;
	Consumer(ReadWrite q) {
		this.q = q;
		new Thread(this, "Consumer").start();
	}
	public void run() {
		int i = 0;
		while(i <= 5) {
			q.get();
			i++;
		}
	}
}

class ReaderWriter {
	public static void main(String args[]) {
		ReadWrite q = new ReadWrite();
		new Producer(q);
		new Consumer(q);
	}
}
