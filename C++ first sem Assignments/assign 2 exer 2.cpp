/*
Pravalika Tirumala
Operations on fractions

*/
#include <iostream>
using namespace std;
	
	class fraction
	{
	long num;
	long den;
//	long NUM;
//	long DEN;
	
	public:
		void setNum(long n);
		void setDen(long d);
		long getNum();
		long getDen();
	void print();
	void add(fraction f1,fraction f2);
	void sub(fraction f1,fraction f2);
	void mul(fraction f1,fraction f2);
	void div(fraction f1,fraction f2);
	void inc(fraction f1);
		
	};

int main()
	{
	fraction f1,f2,f3,f4,f5,f6,f7;
	f1.setDen(2L);
	f1.setNum(0L);
	cout<<"reduced form of fraction is:";
	f1.print();
	
	f2.setDen( 4L);
	f2.setNum( 3L);
	cout<<"reduced form of fraction is:";
	f2.print();
	
	f3.add( f1, f2);
	cout<<"reduced form of sum of two fractions is:";
    f3.print();
    
    f4.sub( f1, f2);
    cout<<"reduced form of substraction  of two fractions is:";
	f4.print();
	
	f5.mul( f1, f2);
	cout<<"reduced form of multiplication of two fractions is:";
    f5.print();

	f6.div( f1, f2);
	cout<<"reduced form of division of two fractions is:";
	f6.print();
	
	f7.inc(f1);
	cout<<"reduced form of incremented fraction is:";
	f7.print();
	return 0;
	}


void fraction ::setDen(long d)
{
den=d;	
}

void fraction :: setNum(long n)
{
	num=n;
}

long gcd(long x,long y)
{
	
	return (x == 0) ? y : gcd (y % x, x );
	
}

void fraction :: print()
{
	
cout<<num/gcd(num,den)<<"/"<<den/gcd(num,den)<<endl;
}

void fraction :: add(fraction f1,fraction f2)
{
	num = ((f1.num*f2.den)+(f2.num*f1.den));
	den = (f1.den*f2.den);
}


void fraction :: sub(fraction f1,fraction f2)
{
	num = ((f1.num*f2.den)-(f2.num*f1.den));
	den = (f1.den*f2.den);
}


void fraction :: mul(fraction f1,fraction f2)
{
	num = (f1.num*f2.num);
	den = (f1.den*f2.den);
}

void fraction :: div(fraction f1,fraction f2)
{
	num = (f1.num*f2.den);
	den= (f2.den*f2.num);
}

void fraction :: inc(fraction f1)
{
	//long NUM = (f1.num+f1.den);
	//long DEN = (f1.den);
	num = ((f1.num*1)+(1*f1.den));
	den  = (f1.den*1);
	
}
long fraction :: getNum()
{
	return num;
}
long fraction :: getDen()
{
	return den;
}











