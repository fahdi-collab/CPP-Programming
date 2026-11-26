#include<iostream>
#include<string>
using namespace std;
int main ()
{
	string name;
	int id,choice,traveldays,bill,baseprice;
	float discount1,discount2,finalprice;
	bool transportpass;
	
	
	
	cout<<"Enter Your Name:";
	getline(cin ,name);
	cout<<"Enter Your ID:";
	cin>>id;
	
	cout<<"\tTransport Choice\t"<<endl;
	cout<<"Press 1 for University Bus(Price=500):\nPress 2 for University Van(Price 1000):\nPRess 3 for Coaster(Price 1200):"<<endl;
	
	cout<<"Enter Choice Here:";
	cin>>choice;
	switch(choice)
	{
		case 1:
			baseprice=500;
			cout<<"You Choosed University Bus:"<<endl;
			break;
			case 2:
				baseprice=1000;
				cout<<"You Choosed University Van:"<<endl;
				break;
				case 3:
					baseprice=1200;
					cout<<"You Choosed Coaster:"<<endl;
					break;
					default:
						cout<<"Choose Right Option:"<<endl;
						return 0;
	
	}
	cout<<"Enter The Number of Travels Days:";
	cin>>traveldays;
	if((traveldays>=1) && (traveldays<=3))
	{
		discount1=0;
		bill=baseprice*traveldays;
		finalprice=bill;
		cout<<"Final Price is:"<<finalprice<<endl;
		if(bill>2000){
			cout<<"Do you have UNi Transport Pass(1 for Yes and 0 For No):";
			cin>>transportpass;
			if(transportpass==1)
			{
				discount2=finalprice*0.05;
				finalprice=finalprice-discount2;
				cout<<"Final Bill After additional discoun is:"<<finalprice<<endl;
				
			}
			else{
				cout<<"No Additional discount Given:"<<endl;
			}
			
		}
		else {
			cout<<"Your FInal Bill is still:"<<finalprice<<endl;
		}
	}
	else if((traveldays>=4) && (traveldays<=5))
	{   bill=baseprice*traveldays;
		discount1=0.05;
		discount1=bill*discount1;
		finalprice=bill-discount1;
		cout<<"Final Price is:"<<finalprice<<endl;
		if(bill>2000){
			cout<<"Do you have UNi Transport Pass(1 for Yes and 0 For No):";
			cin>>transportpass;
			if(transportpass==1)
			{
				discount2=finalprice*0.05;
				finalprice=finalprice-discount2;
				cout<<"Final Bill After additional discoun is:"<<finalprice<<endl;
				
			}
			else{
				cout<<"No Additional discount Given:"<<endl;
			}
			
		}
		else {
			cout<<"Your FInal Bill is still:"<<finalprice<<endl;
		}
	}
	else if((traveldays>=6) && (traveldays<=7))
	{   bill=baseprice*traveldays;
		discount1=0.10;
		discount1=bill*discount1;
		finalprice=bill-discount1;
		cout<<"Final Price is:"<<finalprice<<endl;
		if(bill>2000){
			cout<<"Do you have UNi Transport Pass(1 for Yes and 0 For No):";
			cin>>transportpass;
			if(transportpass==1)
			{
				discount2=finalprice*0.05;
				finalprice=finalprice-discount2;
				cout<<"Final Bill After additional discoun is:"<<finalprice<<endl;
				
			}
			else{
				cout<<"No Additional discount Given:"<<endl;
				cout<<"Final Price is:"<<finalprice;
			}
			
		}
		else {
			cout<<"Your FInal Bill is still:"<<finalprice<<endl;
		}
	}
	else if((traveldays<1) || (traveldays>7))
	{
		cout<<"Invalid"<<endl;
	}
else {
	cout<<"Choose RIght Details:";
}
cout<<"+++++++++Bill Recipt++++++++"<<endl;
cout<<"Name:"<<name<<endl;
cout<<"ID Number:"<<id<<endl;
cout<<"Transport Type:"<<choice<<endl;
cout<<"Number of Days for Travel:"<<traveldays<<endl;
cout<<"Base Fare:"<<baseprice<<endl;
cout<<"1st Discount:"<<discount1<<endl;
cout<<"2nd Discount:"<<discount2<<endl;
cout<<"Final BiLL:"<<finalprice<<endl;
return 0;
}

