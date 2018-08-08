#include<iostream>
#include<stdio.h>
#include<ctype.h>

using namespace std;

char continuar='\n';
double money=0;
char check='\n';
char saving='\n';

int main()
{
int option='\0';


while(toupper(continuar)!='N')
{
	cout<<"\t\tStudent Grade Program\n"<<"\t\t\tMAIN MENU"<<endl;
	cout<<"1.\tEnter name\n2.\tEnter Test scores\n3.\tDisplay test Scores\n4.\tIf code\n9.\tExit"<<endl;
	cin.ignore();
	cin>>option;
		
	switch(option)
	{
		case 1:
			cout<<"Intro name"<<endl;
		break;
		
		case 2:
			cout<<"Test scores"<<endl;
		break;
		
		case 3:
			cout<<"display"<<endl;
		break;
		
		case 4:
		
			money=0;
			check='\n';
			saving='\n';
	
			cout<<"New program x for testing c++ \n""Please How much money do you have?"<< endl;
			cin>>money;
			cout<<"Do you have a check account (y/n)?" << endl;
			cin>> check;
			cout<<"Do you have a saving account (y/n)?" << endl;
			cin>>saving;
	
			if(money>=25000)
			{
				cout<<"You are a platinum member" << endl;
			}
			else if(money>=10000 && toupper(check)=='Y' && toupper(saving)=='Y')
			{
				cout<<"You are a gold member" << endl;
			}
			else if(money >=10000 && toupper(check)=='Y'|| money >=10000 && toupper(saving)=='Y')
			{
				cout<<"You are a sylver member" << endl;
			}
			else if(money<=10000)
			{
				cout<<"You are a copper member" << endl;
			}
			else
				cout<<"NOT a member" << endl;
		break;
		
		case 9:
		continuar='N';
		break;
		
		default:
		cout<<"Your choice is not correct please select again"<<endl;
		cin>>option;
	}
	
}
}

