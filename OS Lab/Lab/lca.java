 import java.util.*;
class thread1 implements Runnable {
	lca w1;
	public int p, k = 0;	
	Thread t;
	thread1(int p, lca w1) {
		t = new Thread(this, "Thread 1");
		this.w1 = w1;
		this.p = p;
		this.t.start();
	}
	public void run() {
		while(k < 5 || p > 1) {
			w1.node1(p);
			p = p/2;
			k++;
		}
	}
}

class thread2 implements Runnable {
	lca w1;
	Thread t;
	public int q, k = 0;
	thread2(int q, lca w1) {
		t = new Thread(this, "Thread 2");
		this.w1 = w1;
		this.q = q;
		this.t.start();
	}
	public void run() {
		while(k < 5 || q > 1) {
			w1.node2(q);
			q = q/2;
			k++;
		}
	}
}

class lca {
	public static int a[] = new int[20];
	public static int b[] = new int[10];
	public static int c[] = new int[10];
	public boolean f = false;
	public static int i = 0, j = 0, x, pos1, pos2;
	synchronized void node1(int p) {
		if(!f)
		try	{
			wait();
		}
		catch(InterruptedException e) {
			System.out.println("\n InterruptedException Caught. \n"+ e);
		}
		f = false;
		b[i++] = a[p/2];
		notify();
	}
	synchronized void node2(int q) {
		if(f)
		try {
			wait();
		}
		catch(InterruptedException e) {
			System.out.println("\n InterruptedException Caught. \n"+ e);
		}
		f = true;
		c[j++] = a[q/2];
		notify();
	}
	public static void main(String args[]) {
		lca w1 = new lca();
		int flag1 = 0, flag2 = 0, m, n, y, z, v;
		try	{
			System.out.println("\n Enter the number of elements in the binary tree: ");
			Scanner s=new Scanner(System.in);
			y=s.nextInt();
			System.out.println("\n Enter the elements one by one: ");
			for(z = 1; z <= y; z++)
				a[z] = s.nextInt();
			System.out.println("\n Enter the first element: ");
				m = s.nextInt();
			System.out.println("\n Enter the second element: ");
				n = s.nextInt();
			for(v = 1; v <= y; v++) {
				if(a[v] == m) {
					pos1 = v;
					flag1++;
				}
				if(a[v] == n) {
					pos2 = v;
					flag1++;
				}
			}
			if(flag1 == 2) {
				new thread1(pos1, w1);
				new thread2(pos2, w1);
				Thread.sleep(300);
				for(m = 0; m < i; m++) {
					if(flag2 == 0)
						for(n = 0; n < j; n++)
							if(b[m] == c[n]) {
								x = b[m];
								flag2 = 1;
								break;
							}
				}
				if(flag2 == 1)
					System.out.println("\n The Least Common Ancestor is: "+x);
				if(x == 0)
					System.out.println("\n No Common Ancestor.");
			}
			else
				System.out.println("\n Element not found.");
		}
		catch(Exception e) {
			System.out.println("\n Error: "+e);
		}
	}
}
