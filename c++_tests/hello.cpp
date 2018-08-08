
#include<iostream>

int main()
{
	std::cout<<"Hello World " << std::endl;
	short age(16);
	const float shoe(8.5), altitude(0), weight(175);
	char gender('F');
	
	std::cout<<age<<"\n"<<shoe<<"\n"<<altitude<<"\n"<<weight<<"\n"<<gender<<std::endl;
	
	char ascii=1;
	std::cout<<ascii<<"\n";
	
	ascii=2;
	std::cout<<ascii<<"\n";
	
	ascii=3;
	std::cout<<ascii<<"\n";
	
	short myage(21);
	const short daysinyear(365);
	int days(0);
	days= daysinyear*myage;
	std::cout<<days<<std::endl;
	
	std::cout<<"C++ is ";
	std::cout<<"Very Cool"<< std::endl;
	
	std::cout<<"What's your age?" << std::endl;
	std::cin>> age;
	std::cout<<"Your input was ";
	
	std::cout.width(20);
	std::cout<<age<<std::endl;
}
