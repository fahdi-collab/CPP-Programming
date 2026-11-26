#include<iostream>
#include<string>
using namespace std;
int main ()
{
	string name;
	int id,unitconsumed;
	float perunitcharge=7.74;
	float bill,rebate=0,surcharge=0,finalbill;
	bool verification;
	
	
	
	cout<<"Enter Your Name:";
	getline(cin, name);
	cout<<"Enter Your id:";
	cin>>id;
	cout<<"Enter Total Units Consumed:";
	cin>>unitconsumed;
	if(unitconsumed<0)
	{
		cout<<"invalid units:"<<endl;
	}
	
	bill=unitconsumed*perunitcharge;
	cout<<"BiLL is:"<<bill<<endl;
	if(bill<1500)
	{
		rebate=0;
		surcharge=0;
		cout<<"NO Rebade or Surcharge is applied:"<<endl;
		finalbill=bill;
		cout<<"Final Bill"<<finalbill<<endl;
	}
	else if (bill>=1500)
	{
		cout<<"Is your Previous bill is paid on time?"<<endl;
		cout<<"Press 1 For Yes and 0 for No:"<<endl;
		cin>>verification;
		if(verification==1)
		{
			rebate=bill*0.05;
			finalbill=bill-rebate;
			cout<<"Final Bill is:"<<finalbill<<endl;
		}
		else
		{
			surcharge=bill*0.05;
			finalbill=bill+surcharge;
			cout<<"Final Bill is:"<<finalbill<<endl;
		}
	}
	
	
	cout<<"============Bill========="<<endl;
	cout<<"Name:"<<name<<endl;
	cout<<"ID:"<<id<<endl;
	cout<<"Unit Consumed:"<<unitconsumed<<endl;
	cout<<"Per Unit Charge:"<<perunitcharge<<endl;
	cout<<"Normal Bill"<<bill<<endl;
	cout<<"Rebate:"<<rebate<<endl;
	cout<<"Surcharge:"<<surcharge<<endl;
	cout<<"Final Bill:"<<finalbill<<endl;
	return 0;
}
