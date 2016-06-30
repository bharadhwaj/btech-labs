import java.rmi.*;
import java.rmi.server.*;
import java.rmi.*;
public class serverimpl extends UnicastRemoteObject implements serverint
{
String a[]=new String[10];
String b[]=new String[10];
int i=0;
int j=0;

public serverimpl()throws Exception
{
}

public void write(String x,String y)
{
a[i]=x;
b[i++]=y;
}

public String[] read1()
{
	return a;
}

public String[] read2()
{
	return b;
}
}

