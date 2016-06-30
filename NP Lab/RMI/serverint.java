import java.rmi.*;
public interface serverint extends Remote
{
void write(String a,String b)throws Exception;
String[] read1()throws Exception;
String[] read2()throws Exception;
}

