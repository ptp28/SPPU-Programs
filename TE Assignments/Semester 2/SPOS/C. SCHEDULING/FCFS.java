import java.util.*;

class Process
{
	int pNo=0;
	int arrivalTime=0;
	int burstTime=0;
	int turnAroundTime=0;
	int waitTime=0;
}

class FCFS
{
	Queue<Process> arrivalQueue = new LinkedList<Process>();
	Queue<Process> readyQueue = new LinkedList<Process>();
	Queue<Process> finishQueue= new LinkedList<Process>();
	
	int numProcess;
	int elapsed=0;
	Process p[];

	FCFS()
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter no. of processes : ");
		numProcess = sc.nextInt();
		p = new Process[numProcess];
		for(int i=0;i<numProcess;i++)
		{
			p[i] = new Process();
			p[i].pNo=i;
			System.out.println("Enter Arrival Time for Process: "+i);
			p[i].arrivalTime = sc.nextInt();
			System.out.println("Enter Burst Time for Process: "+i);
			p[i].burstTime=sc.nextInt();
		}
	}
	
	void setArrivalQueue()
	{
		Process temp;
		for(int i=0; i<numProcess-1 ;i++)
		{
			for(int j=i+1; j<numProcess ; j++)
			{
				if(p[j].arrivalTime < p[i].arrivalTime)
				{
					temp = p[j];
					p[j] = p[i];
					p[i] = temp;
				}
			}
		}
		
		for(int i=0;i<numProcess;i++)
		{
			arrivalQueue.add(p[i]);
		}
	}
	
	void setReadyQueue()
	{
		for(int i=0 ; i<arrivalQueue.size() ;i++)
		{
			Process p = arrivalQueue.remove();
			if(p.arrivalTime <= elapsed)
			{
				readyQueue.add(p);
			}
			else
			{
				arrivalQueue.add(p);
			}
		}
	}
	
	void calculateFCFS()
	{
		setArrivalQueue();
		while(!arrivalQueue.isEmpty() || !readyQueue.isEmpty())
		{
			if(!arrivalQueue.isEmpty())
			{
				setReadyQueue();
			}
			
			if(!readyQueue.isEmpty())
			{
				Process p = readyQueue.remove();
				elapsed = elapsed + p.burstTime;
				p.turnAroundTime = elapsed - p.arrivalTime;
				p.waitTime = p.turnAroundTime - p.burstTime;
				finishQueue.add(p);
			}
			else
			{
				elapsed = elapsed + 1;
			}
		}
	}
	
	void display()
	{
		double avgWaitTime=0;
		double avgTurnAroundTime=0;
		System.out.println("PN \t AT \t BT \t TAT \t WT");
		while(!finishQueue.isEmpty())
		{
			Process p = finishQueue.remove();
			System.out.println(p.pNo + " \t " + p.arrivalTime + " \t " + p.burstTime + " \t "+ p.turnAroundTime + " \t "+ p.waitTime);
			avgWaitTime = avgWaitTime + p.waitTime;
			avgTurnAroundTime = avgTurnAroundTime + p.turnAroundTime; 
		}
		avgWaitTime = avgWaitTime/numProcess;
		avgTurnAroundTime = avgTurnAroundTime/numProcess;
		System.out.println("Average Waiting Time is: "+avgWaitTime);
		System.out.println("Average Turn Around Time is: "+avgTurnAroundTime);
	}

	public static void main(String args[])
	{
		FCFS f = new FCFS();
		f.calculateFCFS();
		f.display(); 	
	}
}