
public class Database 
{
	String name;
	int rollNo;
	double percentage;
	Database()
	{
		rollNo = 0;
		percentage = 0.0;
	}
	Database(int rollNo,String name,double percentage)
	{
		this.name = name;
		this.rollNo = rollNo;
		this.percentage = percentage;
	}
	
	void show()
	{
		System.out.println("ROLL NUMBER : " + rollNo);
		System.out.println("NAME : " + name);
		System.out.println("PERCENTAGE : " + percentage);
	}
}
