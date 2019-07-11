import java.util.*;

class Process
{
	int pNo=0;
	int arrivalTime=0;
	int burstTime=0;
	int turnAroundTime=0;
	int waitTime=0;
	int priority=-1;
}

class Priority
{
	Queue<Process> arrivalQueue = new LinkedList<Process>();
	Queue<Process> readyQueue = new LinkedList<Process>();
	Queue<Process> finishQueue= new LinkedList<Process>();
	int numProcess;
	int elapsed=0;
	Process p[];

	Priority()
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter no. of processes : ");
		numProcess = sc.nextInt();
		p = new Process[numProcess];

		for(int i=0;i<numProcess;i++)
		{
			p[i] = new Process();
			p[i].pNo=i;
			System.out.println("Enter arrival Time for Process: "+i);
			p[i].arrivalTime = sc.nextInt();
			System.out.println("Enter Burst Time for Process: "+i);
			p[i].burstTime=sc.nextInt();
			System.out.println("Enter Priority for Process: "+i);
			p[i].priority=sc.nextInt();
		}
	}
	
	void setArrivalQueue()
	{
		Process temp;
		for(int i=0; i<numProcess-1 ;i++)
		{
			for(int j=i+1; j<numProcess ; j++)
			{
				if(p[j].priority < p[i].priority)
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
		int asize = arrivalQueue.size();
		for(int i=0;i<asize;i++)
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
	
	void cal()
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
				//System.out.println("In readyQueue Queue");
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
		double avgWaitTime=0, avgTurnAroundTime=0;
		System.out.println("PN \t AT \t BT \t TAT \t WT \t PT");
		while(!finishQueue.isEmpty())
		{
			Process p = finishQueue.remove();
			System.out.println(p.pNo + " \t " + p.arrivalTime + " \t " + p.burstTime + " \t "+ p.turnAroundTime + " \t "+ p.waitTime + " \t "+p.priority);
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
		Priority p = new Priority();
		p.cal();
		p.display(); 	
	}
}
