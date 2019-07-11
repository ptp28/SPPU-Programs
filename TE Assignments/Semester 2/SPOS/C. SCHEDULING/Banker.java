import java.util.*;

class Banker
{
	int numProcess = 0;
	int numResources = 0;
	int maxMatrix[][];
	int allocationMatrix[][];
	int needMatrix[][];
	int availableMatrix[];
	int maxResources[];
	String str = "";
	Banker()
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter no. of processes : ");
		numProcess = sc.nextInt();
		System.out.println("Enter no. of resources : ");
		numResources = sc.nextInt();
		
		maxMatrix = new int[numProcess][numResources];
		allocationMatrix = new int[numProcess][numResources];
		needMatrix = new int[numProcess][numResources];
		availableMatrix = new int[numResources];
		maxResources = new int [numResources]; 
		
		System.out.println("Enter maximum no. of units available for each resource:");
		for(int i=0;i<numResources;i++)
		{
			System.out.println("Enter value for resource "+i);
			maxResources[i] = sc.nextInt();
			availableMatrix[i] = maxResources[i];
		}
		for(int i=0;i<numProcess;i++)
		{
			for(int j=0;j<numResources;j++)
			{
				System.out.println("Enter allocated by process "+i+" for resource "+j);
				allocationMatrix[i][j] = sc.nextInt();
				availableMatrix[j] = availableMatrix[j] - allocationMatrix[i][j];
				System.out.println("Enter maximum Requirement for process "+i+" for resource "+j);
				maxMatrix[i][j] = sc.nextInt();
				needMatrix[i][j] = maxMatrix[i][j]-allocationMatrix[i][j];
			}
		}
	}
	
	boolean checkmaxMatrix()
	{
		for(int i=0;i<numProcess;i++)
		{
			for(int j=0;j<numResources;j++)
			{
				if(maxMatrix[i][j]>maxResources[j])
				{
					return true;
				}
			}
		}
		return false;
	}
	
	boolean checkNeed()
	{
		for(int i=0;i<numProcess;i++)
		{
			for(int j=0;j<numResources;j++)
			{
				if(needMatrix[i][j]<0)
				{
					return true;
				}
			}
		}
		return false;
	}

	
	boolean checkSafe()
	{
		if(checkmaxMatrix() || checkNeed())
		{
			return false;
		}
		int work[] = new int[numResources];
		int need1[][] = new int [numProcess][numResources];
		
		for(int i=0;i<numProcess;i++)
		{
			for(int j=0;j<numResources;j++)
			{
				need1[i][j] = needMatrix[i][j];
			}
		}	
		
		for(int i=0;i<numResources;i++)
		{
			work[i] = availableMatrix[i];
		}
	
		int flag = 0;
		int flag1 = 0;
		boolean exe[] = new boolean[numProcess];
		for(int i=0;i<numProcess;i++)
		{
			exe[i] = false;
		} 
		
		while(flag == 0)
		{
			flag = 1;
			for(int i=0; i<numProcess;i++)
			{
				for(int j=0;j<numResources;j++)
				{
					if(need1[i][j]>work[j])
					{
						flag1 = 1;
						break;
					}
				}
				if(flag1 == 0)
				{
					for(int j=0;j<numResources;j++)
					{
						work[j] = work[j] + allocationMatrix[i][j];
						need1[i][j] = maxResources[j] + 10000;	
					}
					exe[i] = true;
					str = str + i +" -> ";
					flag = 0;
				}
				else
				{
					flag1 = 0;
				}
			}
		}
		for(int i=0;i<numProcess;i++)
		{
			if(exe[i]==false)
			return false;
		}
		return true;
	}
	
	void menu()
	{
		Scanner sc = new Scanner(System.in);
		
		if(checkSafe())
		{
			System.out.println("Safe State \n"+str);
		}
		else
		{
			System.out.println("Not a Safe State");
		}
	}
	
	public static void main(String args[])
	{
		Banker b = new Banker();
		b.menu();
	}
}
