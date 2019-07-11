import java.util.*;
class fcfs
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		int n,avgw=0,avgt=0;
		System.out.println("Enter No. of Processes");
		n=sc.nextInt();
		int arrival[]=new int[n];
		int burst[]=new int[n];
		int start[]=new int[n];
		int finish[]=new int[n];
		int wait[]=new int[n];
		int turn[]=new int[n];
		for(int i=0;i<n;i++)
		{
			System.out.println("Enter arrival time for process "+(i+1));
			arrival[i]=sc.nextInt();
			System.out.println("Enter burst time for process "+(i+1));
			burst[i]=sc.nextInt();
		}
		start[0]=arrival[0];
		for(int i=1;i<n;i++)
		{
			start[i]=start[i-1]+burst[i-1];
		}
		for(int i=0;i<n;i++)
		{
			finish[i]=start[i]+burst[i];
		}
		for(int i=0;i<n;i++)
		{
			turn[i]=finish[i]-arrival[i];
		}
		for(int i=0;i<n;i++)
		{
			wait[i]=turn[i]-burst[i];	
		}
		for(int i=0;i<n;i++)
		{
			avgw=avgw+wait[i];
			avgt=avgt+turn[i];
		}
		avgw=avgw/n;
		avgt=avgt/n;
		System.out.println("Arrival\tBurst\tstart\tFinish\tWait\tTurnaround");
		for(int i=0;i<n;i++)
		{
			System.out.println(arrival[i]+"\t"+burst[i]+"\t"+start[i]+"\t"+finish[i]+"\t"+wait[i]+"\t"+turn[i]);
		}
		System.out.println("Avg Wait Time---> "+avgw);
		System.out.println("Avg turn Time---> "+avgt);
	}
}
