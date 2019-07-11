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

class RR
{
	Queue<Process> arrivalQueue = new LinkedList<Process>();
	Queue<Process> readyQueue = new LinkedList<Process>();
	Queue<Process> finishQueue= new LinkedList<Process>();
	int numProcess;
	int elapsed=0;
	int quantum=0;
	Process p[];
	String seq = "";
	RR()
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter no. of processes:");
		numProcess = sc.nextInt();
		p = new Process[numProcess];

		System.out.println("Enter size of Quantum:");
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
		setArrival();
		int rrflag=0;
		Process p1=p[0];
		while(!arrivalQueue.isEmpty() || !readyQueue.isEmpty())
		{
			if(!arrivalQueue.isEmpty())
			{
				setReadyQueue();
			}
			
			if(rrflag == 1)
			{
				readyQueue.add(p1);
				rrflag = 0;
			}
			
			if(!readyQueue.isEmpty())
			{
				p1 = readyQueue.remove();
				if(p1.rburst <= quantum)
				{
					elapsed = elapsed + p1.rburst;
					p1.turnAroundTime = elapsed - p1.arrivalTime;
					p1.waitTime = p1.turnAroundTime - p1.burstTime;
					finishQueue.add(p1);
					seq = seq + p1.pNo + " -> ";		
				}
				else
				{
					elapsed = elapsed + quantum;
					p1.rburst = p1.rburst - quantum;
					if(!arrivalQueue.isEmpty())
					{
						rrflag=1;
					}
					else
					{
						readyQueue.add(p1);	
					}
					seq = seq + p1.pNo + " -> ";
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
		double avgWaitingTime = 0,avgTurnAroundTime = 0;
		System.out.println("PN \t AT \t BT \t TAT \t WT");
		while(!finishQueue.isEmpty())
		{
			Process p = finishQueue.remove();
			System.out.println(p.pNo + " \t " + p.arrivalTime + " \t " + p.burstTime + " \t "+ p.turnAroundTime + " \t "+ p.waitTime);
			avgWaitingTime = avgWaitingTime + p.waitTime;
			avgTurnAroundTime =avgTurnAroundTime + p.turnAroundTime; 
		}
		avgWaitingTime = avgWaitingTime/numProcess;
		avgTurnAroundTime = avgTurnAroundTime/numProcess;
		System.out.println("Average Waiting Time is: "+avgWaitingTime);
		System.out.println("Average Turn Around Time is: "+avgTurnAroundTime);
		System.out.println(seq);
	}
	public static void main(String args[])
	{
		RR r = new RR();
		r.cal();
		r.display(); 	
	}
}
