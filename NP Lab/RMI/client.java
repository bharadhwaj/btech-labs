import java.io.*;
import java.rmi.*;
import java.util.*;
public class client
{
public static void main(String args[])throws Exception
{
try
{
int i=0;
String a[]=new String[10];
String b[]=new String[10];
Scanner m=new Scanner(System.in);
String s="rmi://localhost/abc";
serverint f=(serverint)Naming.lookup(s);
System.out.println("\nEnter the no.of login informations:");
int n=m.nextInt();
//DataInputStream m=new DataInputStream(System.in);
for(i=0;i<n;i++)
	{
	System.out.println("\nEnter the username & time of login:");
	String n1=m.next();
	String n2=m.next();
	f.write(n1,n2);
	}
a=f.read1();
b=f.read2();
System.out.println("\nUSER\tLOGIN TIME");
for(i=0;i<n;i++)
	System.out.println(a[i]+"\t"+b[i]);
}
catch(Exception e)
{
System.out.println(e);
}
}
}
