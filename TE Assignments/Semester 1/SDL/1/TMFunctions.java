import java.util.*;

class TMFunctions
{
	Scanner sc = new Scanner(System.in);
	TreeMap<Integer,Database> hm=new TreeMap<Integer,Database>(); 
	TreeMap<Integer,Database> hmTemp=new TreeMap<Integer,Database>(); 
	static int rollNo=0;
	
	public void addData()
	{
		String name;
		double percentage;
		int num;
		
		System.out.println("NUMBER OF ENTRIES : ");
		num = sc.nextInt();
		sc.nextLine();
		
		hmTemp.clear();
		for(int i = 0 ; i < num ; i++)
		{
			try
			{
				rollNo++;
				System.out.println("Enter NAME : ");
				name = sc.nextLine();
				System.out.println("Enter PERCENTAGE : ");
				percentage = sc.nextDouble();
				sc.nextLine();
				Database d = new Database(rollNo,name,percentage);
				hmTemp.put(rollNo,d);
			}
			catch(InputMismatchException e)
			{
				System.out.println("WRONG DATATYPE ENTERED");
			}
		}
		hm.putAll(hmTemp);
	}
	
	public void getData()
	{
		System.out.println("\nTHE DATA IN THE TREEMAP IS\n");
		for(Map.Entry<Integer,Database> m : hm.entrySet())
		{  
			int r = m.getKey();
			Database dd = m.getValue();
			dd.show();
		}
	}
	
	public void removeData()
	{
		
		int key=0,choice,sIndex=0,lIndex=1,flag;
		Database removed = new Database();
		System.out.println("1. Remove SINGLE entry\n2. Remove MULTIPLE entries\nEnter your choice : ");
		choice = sc.nextInt();
		
		switch(choice)
		{
		case 1:
			System.out.println("Enter KEY : ");
			do
			{
				try
				{
					key = sc.nextInt();
					flag=0;
				}
				catch(InputMismatchException e)
				{
					System.out.println("WRONG DATATYPE ENTERED");
					flag=1;
				}
			}while(flag==1);
			hmTemp.clear();
			
			removed = hm.remove(key);
			
			hmTemp.put(key,removed);
			break;
		case 2:
			do
			{
				try
				{
					System.out.println("DELETE from ROLL NUMBER : ");
					sIndex = sc.nextInt();
					System.out.println("DELETE till ROLL NUMBER : ");
					lIndex = sc.nextInt();
					flag=0;
				}
				catch(InputMismatchException e)
				{
					System.out.println("WRONG DATATYPE ENTERED");
					flag = 1;
				}
				hmTemp.clear();
			}while(flag==1);
			
			for(int i = sIndex ;i < lIndex ; i++ )
			{
				removed = (Database)hm.remove(i);
				removed.show();
				hmTemp.put(i, removed);
			}
			break;
		}
		System.out.println("\n THE FOLLOWING DATA WILL BE REMOVED PERMANENTLY \n");
		for(Map.Entry<Integer,Database> mm : hmTemp.entrySet())
		{  
			int r = mm.getKey();
			Database dd = mm.getValue();
			System.out.println("HELOOO");
			dd.show();
		}
		System.out.println("DO YOU WANT TO CONTINUE (y/N) : ");
		char ch = sc.next().charAt(0);
		if(ch=='y')
		{
			hmTemp.clear();
		}
		else
		{
			hm.putAll(hmTemp);
		}	
	}
	
	public void searchData()
	{
		int key=0,flag;
		System.out.println("Enter KEY : ");
		do
		{
			try
			{
				key = sc.nextInt();
				flag=0;
			}
			catch(InputMismatchException e)
			{
				System.out.println("WRONG DATATYPE ENTERED");
				flag=1;
			}
		}while(flag==1);
		if(hm.containsKey(key))
		{
			System.out.println("THE KEY IS PRESENT");
		}
		else
		{
			System.out.println("THE KEY IS NOT PRESENT");
		}
	}
	
	public void getSize()
	{
		System.out.println("The SIZE of the TreeMap is : " + hm.size());
	}
	
}
