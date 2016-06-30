import java.net.*;
import java.rmi.*;
public class server
{
public static void main(String args[])
{
try
	{
	serverimpl m=new serverimpl();
	Naming.rebind("abc",m);
	}
	catch(Exception e)
	{
	System.out.println("Exception"+e);
	}
}
}

