	import java.util.*;
import java.io.*;
class X
{
	int x,rstamp,wstamp;
	X()
	{
		x=7;
		rstamp=-1;
		wstamp=-1;
	}
	public synchronized int readitem(int ts,int id)
	{
		if(wstamp>ts)
		{
			System.out.println("\nTransaction "+id+" TS="+ts);
			System.out.println("read_TS(X)="+rstamp);
			System.out.println("write_TS(X)="+wstamp+"\nRead Failed, Aborting!");
			return 0;
		}
		else
		{
			System.out.println("\nTransaction "+id+" TS="+ts);
			System.out.println("read_TS(X)="+rstamp);
			System.out.println("write_TS(X)="+wstamp+" Read Value="+x);
			if(ts >  rstamp)
				rstamp=ts;
			return 1;
		}
	}
	public synchronized int writeitem(int ts,int id)
	{
		if(wstamp> ts){
			System.out.println("\nTransaction "+id+" TS="+ts);
			System.out.println("read_TS(X)="+rstamp);
			System.out.println("write_TS(X)="+wstamp+"\nWrite skipped.");
			return 1;

		
		}
		if(rstamp>ts)
		{
			System.out.println("\nTransaction "+id+" TS="+ts);
			System.out.println("read_TS(X)="+rstamp);
			System.out.println("write_TS(X)="+wstamp+"\nWrite Failed, Aborting!");
			return 0;
		}
		else
		{
			x=x+10;
			System.out.println("\nTransaction "+id+" TS="+ts);
			System.out.println("read_TS(X)="+rstamp);
			System.out.println("write_TS(X)="+wstamp+" Wrote value="+x);
			wstamp=ts;
			return 1;
		}
	}
}

class transaction extends Thread
{
	int ts,id;
	int wrote = 0;
	int read = 0;
	X item;
	transaction(X x,int id,int t)
	{
		item=x;
		ts=t;
		this.id=id;
	}
	public void run()
	{
		while(wrote == 0 || read== 0)
		{
			if(read == 0){
				if(item.readitem(ts,id) == 1){
				
					read = 1;
					continue;
			}else{
				break;
			}
				
				
			}
			if(read == 1 && wrote == 0){
				if(item.writeitem(ts,id) == 1){
					wrote = 1;
					continue;
				}else{
					break;
				}
				
			}
		}
	}
}

class trans
{
	static int maxts=0;
	public static void main(String args[]) throws IOException
	{
		DataInputStream in=new DataInputStream(System.in);
		int num;
		X item=new X();
		System.out.println("\nEnter the no. of transactions: ");
		num=Integer.parseInt(in.readLine());
		for(int i=0;i<num;i++)
			new transaction(item,i,maxts++).start();
	}
}
		
				
