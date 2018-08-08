#include<iostream>
#include<math.h>
using namespace std;

double cuadraticp(int,int,int);
double cuadraticn(int,int,int);

const short deux=2;
const short quatre=4;
int a;
int b;
int c;
double x1=0.00000F;
double x2=0.00000F;
double discriminant=0.00000F;

int main(){
	cout<< "This Program calculates the roots of a quadratic formula\n";
	cout<< "Please enter the value of a"<< endl;
	cin>>a;
	while (a==0)
	{
		cout<<"ERROR a can't be 0\n";
		cout<< "Please enter the value of a"<< endl;
		cin>>a;
	}
	cout<< "Please enter the value of b"<< endl;
	cin>>b;
	cout<< "Please enter the value of c"<< endl;
	cin>>c;
	
	discriminant= (b*b)-(quatre*a*c);
	
	if(discriminant<=0)
	{
	
	cout<<"ERROR It will become complex number\n";
	return 0;
	}
	
	x1=cuadraticp(a,b,c);
	x2=cuadraticn(a,b,c);
	
	cout<<x1<<"\n"<<x2<<endl;	
}

double cuadraticp(int a,int b,int c){

	int raiz1=0;
	raiz1= (-b+(sqrt(pow(b,deux)-(quatre*a*c))))/(deux*a);
	return raiz1;
}

double cuadraticn(int a,int b,int c){

	double raiz2=0;
	raiz2= (-b-(sqrt(pow(b,deux)-(quatre*a*c))))/(deux*a);
	return raiz2;
}
