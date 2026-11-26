#include<iostream>
#include<string>
using namespace std;
int main()
{
	string name;
	int rollno,marks,attendance;
	cout<<"Enter your name:";
	getline(cin, name);
	cout<<"Enter your roll number:";
	cin>>rollno;
	cout<<"Enter Your Marks out off 100:";
	cin>>marks;
	if(marks<40)
	{
		cout<<"Failed"<<endl;

		cout<<"scholarship not available:"<<endl;
	}
	else if(marks<=59)
	{
		cout<<"Passed"<<endl;
		cout<<"Scholarship not available:"<<endl;
	}
	else if(marks<=79)
	{
		cout<<"Passed"<<endl;
		cout<<"Eligible for 5% Scholarship:"<<endl;
	}
	else if((marks>=80) && (marks<=100))
	{
		cout<<"Passed:"<<endl;
		cout<<"Enter Your Attendence:";
		cin>>attendance;
		if(attendance>=85)
		{
			cout<<"Eligible for 15% of scholarship."<<endl;
			
		}
		else
		{
			cout<<"scholarship rejected due to LOW attendance."<<endl;
			
		}
	
	}
	else 
	{ 
	cout<<"Invalid Marks:";
	}
	return 0;
}
