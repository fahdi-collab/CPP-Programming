#include<iostream>
#include<string>
using namespace std;
int main()
{
	string name;
	int rollno,choice;
	float size,baseprice,originalprice,discount,finalprice;
	bool card;
	
	
	
	
	
	cout<<"Enter Your Name:";
	getline(cin, name);
	cout<<"Enter Your Roll No:";
	cin>>rollno;
	
	cout<<"\tMenu\t"<<endl;
	cout<<"Press 1 for Burger"<<endl;
	cout<<"Press 2 for Pizza"<<endl;
	cout<<"Press 3 for Pepsi"<<endl;
	cout<<"Press 4 for Pasta"<<endl;
	
	cout<<"Enter Your Choice Here:";
	cin>>choice;
	switch(choice){
		case 1:
			baseprice=250.0;
			cout<<"You Choiced Burger:"<<endl;
			cout<<"For Small Press (1)\nFor Medium Press(1.5)\nFor Large Press(2):"<<endl;
			cout<<"Enter the size:";
			cin>>size;
			if(size==1.0)
			{
				originalprice=1*baseprice;
				cout<<"Price is:"<<originalprice<<endl;
			}
			else if(size==1.5)
			{
				originalprice=1.5*baseprice;
				cout<<"Price is:"<<originalprice<<endl;
			}
			else if(size==2.0)
			{
				originalprice=2*baseprice;
				cout<<"Price is:"<<originalprice<<endl;
			}
			else
			{
				cout<<"Enter Right Choice:";
			}
			break;
			case 2:
				baseprice=300.0;
				cout<<"You choosed Pizza:"<<endl;
				cout<<"For Small Press (1)\nFor Medium Press(1.5)\nFor Large Press(2):"<<endl;
				cout<<"Enter The Size:";
				cin>>size;
				if(size==1.0)
				{
					originalprice=1*baseprice;
				cout<<"Price is:"<<originalprice<<endl;
			}
			else if(size==1.5)
			{
				originalprice=1.5*baseprice;
				cout<<"Price is:"<<originalprice<<endl;
			}
			else if(size==2.0)
			{
				originalprice=2*baseprice;
				cout<<"Price is:"<<originalprice<<endl;
			}
			else
			{
				cout<<"Enter Right Choice:";
			}
			break;
			case 3:
				baseprice=400.0;
				cout<<"You choosed Pepsi:"<<endl;
				cout<<"For Small Press (1)\nFor Medium Press(1.5)\nFor Large Press(2):"<<endl;
				cout<<"Enter The Size:";
				cin>>size;
				if(size==1.0)
				{
					originalprice=1*baseprice;
				cout<<"Price is:"<<originalprice<<endl;
			}
			else if(size==1.5)
			{
				originalprice=1.5*baseprice;
				cout<<"Price is:"<<originalprice<<endl;
			}
			else if(size==2.0)
			{
				originalprice=2*baseprice;
				cout<<"Price is:"<<originalprice<<endl;
			}
			else
			{
				cout<<"Enter Right Choice:";
			}
			break;
			case 4:
				baseprice=500.0;
				cout<<"You choosed Pasta:"<<endl;
				cout<<"For Small Press (1)\nFor Medium Press(1.5)\nFor Large Press(2):"<<endl;
				cout<<"Enter The Size:";
				cin>>size;
				if(size==1.0)
				{
					originalprice=1*baseprice;
				cout<<"Price is:"<<originalprice<<endl;
			}
			else if(size==1.5)
			{
				originalprice=1.5*baseprice;
				cout<<"Price is:"<<originalprice<<endl;
			}
			else if(size==2.0)
			{
				originalprice=2*baseprice;
				cout<<"Price is:"<<originalprice<<endl;
			}
			else
			{
				cout<<"Enter Right Choice:";
			}
			break;
			default:
			{
				cout<<"Enter Right menu Number:";
			}
				}
				if(originalprice < 300)
    {
        discount = 0;
        finalprice = originalprice;
    }
    else
    {
        cout << "\nDo you have a valid university card?" << endl;
        cout << "Enter 1 for Yes and 0 for No: ";
        cin >> card;

        if(card == 1)
        {
            discount = originalprice * 0.10;
            finalprice = originalprice - discount;
        }
        else
        {
            discount = 0;
            finalprice = originalprice;
        }
					
				}
			cout<<"===========Bill Receipt============"<<endl;
			cout<<"Name:"<<name<<endl;
			cout<<"Roll no:"<<rollno<<endl;
			cout<<"Choice:"<<choice<<endl;
			cout<<"Size:"<<size<<endl;
			cout<<"OriginalPrice:"<<originalprice<<endl;;
			cout<<"Discount:"<<discount<<endl;
			cout<<"Final Price:"<<finalprice<<endl;
	
	return 0;
	}
	


