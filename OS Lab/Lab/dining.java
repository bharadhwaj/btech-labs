class fork
{
	boolean available=true;
	int num;
	fork(int n)
	{
	num=n;
	}
	
	synchronized  void take()
	{    
		String s=Thread.currentThread().getName();
		try
		{
		       if(available==false)
		          {
		 		System.out.println(s+" is thinking. . . .");
		 		wait();
			  }
		}
		catch(Exception e)
		{
		}
		System.out.println(s+" took fork "+num);
	    	available = false;
	}
	
	synchronized  void  putfork()
	{
		String s=Thread.currentThread().getName();
		System.out.println(s+" put fork "+num+" down");
		 available=true;
		 notify();
	}	 
}

class phil implements Runnable
{	
	int num;
	fork left,right;
	Thread t;
	phil(int n,String s,fork l,fork r)
	{
		left=l;
		right=r;
		num=n;
		t=new Thread(this,s);
		t.start();
	}
	
	public void run()
	{
		String s=Thread.currentThread().getName();
		if(num%2==0)
		{  
			right.take();
			left.take();
			try
			{
				System.out.println(s+" is eating. . . .");
				Thread.sleep(1000);
			}
			catch(Exception e)
			{
			}
			left.putfork();
			right.putfork();

		}
		else
		{
		        left.take();
			right.take();
			try
			{
				System.out.println(s+" is eating. . . .");
				Thread.sleep(1000);
			}
			catch(Exception e)
			{
			}
			right.putfork();
			left.putfork();
		}
	}

		
}


class dining
{
	public static void main(String[] args)
	{       
		fork f1=new fork(1);
		fork f2=new fork(2);
		fork f3=new fork(3);
		fork f4=new fork(4);
		fork f5=new fork(5);
		 
		phil p1=new phil(1,"philosopher 1",f1,f2);
		phil p2=new phil(2,"philosopher 2",f2,f3);
		phil p3=new phil(3,"philosopher 3",f3,f4);
		phil p4=new phil(4,"philosopher 4",f4,f5);
		phil p5=new phil(5,"philosopher 5",f5,f1);
				
	}
}
