import java.util.*;
class calc
{
	static
	{
		System.loadLibrary("calc");
	}
	private native int add(int a,int b);
	public static void main(String args[])
	{
		System.out.println("Addition is "+new calc().add(20,30));
	} 
}	
