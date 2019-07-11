import java.util.*;

class Process
{
	int pNo=0;
	int arrivalTime=0;
	int burstTime=0;
	int turnAroundTime=0;
	int waitTime=0;
	int rburst=0;
}

class SJF
{
	Queue<Process> arrivalQueue = new LinkedList<Process>();
	Queue<Process> readyQueue = new LinkedList<Process>();
	Queue<Process> finishQueue= new LinkedList<Process>();
	int numProcess;
	int elapsed=0;
	int quantum=0;
	Process p[];

	SJF()
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter no. of Processes : ");
		numProcess = sc.nextInt();
		p = new Process[numProcess];

		System.out.print("Enter size of Quantum : ");
		quantum = sc.nextInt(); 

		for(int i=0;i<numProcess;i++)
		{
			p[i] = new Process();
			p[i].pNo=i;
			System.out.println("Enter arrival Time for Process: "+i);
			p[i].arrivalTime = sc.nextInt();
			System.out.println("Enter Burst Time for Process: "+i);
			p[i].burstTime=sc.nextInt();
			p[i].rburst=p[i].burstTime;
		}
	}
	
	void setArrival()
	{
		Process temp;
		for(int i=0; i<numProcess-1 ;i++) 		//Sorting it in acsending order according to burst time
		{
			for(int j=i+1; j<numProcess ; j++)
			{
				if(p[j].burstTime < p[i].burstTime)
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
		for(int i=0;i<arrivalQueue.size();i++)
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
	
	void sortReadyQueue()
	{
		Process p1[] = new Process[numProcess];	//Temporary array used for sorting
		int queueSize = readyQueue.size();

		for(int i=0;i<queueSize;i++)
		{
			p1[i] = readyQueue.remove();	
		}
		
		Process temp;
		for(int i=0; i<queueSize-1 ;i++)
		{
			for(int j=i+1; j<queueSize ; j++)
			{
				if(p1[j].rburst < p1[i].rburst)
				{
					temp = p1[j];
					p1[j] = p1[i];
					p1[i] = temp;
				}
			}
		}
		for(int i=0;i<queueSize;i++)
		{
			readyQueue.add(p1[i]);
		}
	}
	
	void cal()
	{
		setArrival();

		while(!arrivalQueue.isEmpty() || !readyQueue.isEmpty())
		{
			if(!arrivalQueue.isEmpty())
			{
				setReadyQueue();
			}
			
			if(!readyQueue.isEmpty())
			{
				if(readyQueue.size() > 1)
				{
					sortReadyQueue();
				}
				Process p = readyQueue.remove();
				if(p.rburst <= quantum)
				{
					elapsed = elapsed + p.rburst;
					p.turnAroundTime = elapsed - p.arrivalTime;
					p.waitTime = p.turnAroundTime - p.burstTime;
					finishQueue.add(p);	
				}
				else
				{
					elapsed = elapsed + quantum;
					p.rburst = p.rburst - quantum;
					readyQueue.add(p);
				}
			}
			else
			{
				elapsed = elapsed + 1;
			}
		}
	}
	
	void display()
	{
		double avgWaitingTime=0,avgTurnAroundTime=0;
		System.out.println("PN \t AT \t BT \t TAT \t WT");
		while(!finishQueue.isEmpty())
		{
			Process p = finishQueue.remove();
			System.out.println(p.pNo + " \t " + p.arrivalTime + " \t " + p.burstTime + " \t "+ p.turnAroundTime + " \t "+ p.waitTime);
			avgWaitingTime = avgWaitingTime + p.waitTime;
			avgTurnAroundTime = avgTurnAroundTime + p.turnAroundTime; 
		}
		avgWaitingTime = avgWaitingTime/numProcess;
		avgTurnAroundTime = avgTurnAroundTime/numProcess;
		System.out.println("Average Waiting Time is: "+avgWaitingTime);
		System.out.println("Average Turn Around Time is: "+avgTurnAroundTime);
	}
	public static void main(String args[])
	{
		SJF s = new SJF();
		s.cal();
		s.display(); 	
	}
}