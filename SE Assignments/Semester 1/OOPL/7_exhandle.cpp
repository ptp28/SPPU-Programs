#include<iostream>
using namespace std;
class Employee
{
	private:
	int age;
	long salary;
	string city;
	int vehicle;
	int check;
	void getAge()
	{
		cout<<"\nEnter age :";
		cin>>age;
	}
	void getSalary()
	{
		cout<<"\nEnter salary :";
		cin>>salary;
	}
	void getCity()
	{
		cout<<"\nEnter city :";
		cin>>city;
	}
	void getVehicle()
	{
		cout<<"\nEnter vehicle type :";
		cin>>vehicle;
	}
	public:
	Employee()
	{
		age=0;
		salary=0;
		city=" ";
		vehicle=0;
		check=0;
	}
    void getAndCheck()
    {
        do
        {
            try
            {
                getAge();
                if(age<=18 || age>=55)
                    throw(1);
                else
                    check++;
            }
            catch (int a)
            {
                    cout<<"\n!!! INVALID AGE !!!";
                    cout<<"\n!!! Age should be between 18 and 55 !!!\n";
            }
        }while(check==0);
        do
        {
            try
            {
                getSalary();
                if(salary<=50000 || salary>=100000)
                    throw(1.0);
                else
                    check++;
            }
            catch (double)
            {
                cout<<"\n!!! INVALID SALARY !!!";
                cout<<"\n!!! Salary should be between 50,000 and 1,00,000 !!!\n";
            }
        }while(check==1);
        do
        {
            try
            {
                getCity();
                if(city !="PUNE" && city !="MUMBAI" && city !="BANGALORE" && city !="CHENNAI" )
                    throw('a');
                else
                    check++;
            }
            catch (char)
            {
                cout<<"\n!!! INVALID CITY !!!";
                cout<<"\n!!! Only 'PUNE' , 'MUMBAI' , 'BANGALORE' and 'CHENNAI' are valid cities !!!\n";
            }
        }while(check==2);
        do
        {
            try
            {
                getVehicle();
                if(vehicle!=4)
                    throw("Error");
                else
                    check++;
            }
            catch (const char *)
            {
                cout<<"\n!!! INVALID VEHICLE !!!";
                cout<<"\n!!! Only 4-Wheelers are allowed !!!\n";
            }
        }while(check==3);
    }
    void display()
	{
		cout<<"\nAge : "<<age;
		cout<<"\nSalary : "<<salary;
		cout<<"\nCity : "<<city;
		cout<<"\nVehicle type : "<<vehicle;
	}
};
int main()
{
	int i;
	Employee e;
	cout<<"\n\n*** ENTER DATA : ***\n\n";
    e.getAndCheck();
    cout<<"\n\n*** THE ENTERED DATA IS : ***\n\n";
	e.display();
    cout<<"\n\n\t*** END ***\n\n";
}
