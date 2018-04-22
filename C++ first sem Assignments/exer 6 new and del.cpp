/* using new and delete keywords
Pravalika Tirumala
*/

#include <iostream>
using namespace std;
#include <string.h>

class Employee
{
char* name;
long ssn;
double salary;
char* company;

public:


 Employee (char* name_,long ssn_,double salary_,char* company_)
 {
 	name= new char [strlen(name_)+1];
 	strcpy(name,name_);
 	company=new char [strlen(company_)+1];
 	strcpy(company,company_);
 	ssn=ssn_;
 	salary=salary_;
 
}
  ~Employee()
{
	cout <<"destructor"<<endl;
	delete name;
delete company;
}
char * getName ( );
char * getCompany( );
double getSalary ( );
long getSsn ( );
void print ( );
} ;
int main ( )
{
Employee E1("John K. Smith", 502817792L, 100000, "IBM");
Employee E2("Bob L. Edward", 555555555, 70000, "IBM");
E1.print();
cout<<endl;
E2.print();
cout<<endl;

return 0;
}
char* Employee :: getName()
{
	return name;
}
char* Employee :: getCompany()
{
	return company;
}
double Employee :: getSalary()
{
	return salary;
}
long Employee :: getSsn()
{
	return ssn;
}
void Employee :: print()
{
	cout<<"company ="<<company<<endl;
	cout<<"name ="<<name<<endl;
	cout<<"ssn ="<<ssn<<endl;
	cout<<"salary ="<<salary<<endl;
}
