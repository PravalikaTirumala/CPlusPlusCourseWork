#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
class STACK 
  {
	private:
	char *s;
	int N;
	public:
	STACK(int maxN)
	{
	s = new char[maxN];
	N = 0;
	};
	int empty() const
	{
		if(N!=0)
		cout<<"not empty"<<endl;
		else
		{
		cout<<"empty"<<endl;
		return N==0;
		}
	}
	void push(char item)
	{
	s[N++]=item;
	}
	char pop()
	{
	return s[--N];
	}
  };

int main()
{
	char e='exit';
	
	char a[70];
	char b[70];
	int z;
while(a != "EXIT")
{
	int i=0,j=0,count=0;
	cout<<endl;
	cout<<"enter expression with operands and operators"<<endl;
	cin>>a;
	int M = strlen(a);
  	cout<<endl;
    	STACK ops(M);
    	cout<<"post-fix expression is"<<endl;
	
	for (i=0; i< M;)
   	{
    for(j;j<M;)
    	{
			if(a[i] == '(')
			{
			i++;
			count=count+1;	
			break;
			}
			if (a[i] == ')')
			{
			b[j]=ops.pop();
			cout<<b[j]<< " ";
			i++;
			j++;
			count=count+1;
			break;
			}
			if ((a[i] == '+') || (a[i] == '*') || (a[i] == '^')) 
			{
			ops.push(a[i]);
			i++;
			break; 
			}
			if ((a[i] >= '0') && (a[i] <= '9')) 
			{
			cout<< a[i] << "  ";
			b[j]=a[i];
			i++;
			j++;
			break;
			}
		}	
	}	
cout<<endl;
for(i=0;i<(M-count);i++)
  	{
  	cout<<b[i]<<"  ";
  	}
	int MN = M-count;
	STACK save(MN);
	cout<<endl;
	cout<<"in modulo 10 is:"<<endl;
	int x,y,z;
	for (i = 0; i< MN;)
   	{ 
		if (b[i] == '+') 
		{
			x=(save.pop()-'0');
			y=(save.pop()-'0');
			z=((x+y) % 10);
			char c=z+'0';
		save.push (c);
		//cout<<z;
		i++;
		//cout<<"one +"<<endl;
		}
		if (b[i] == '*') 
		{
			x=(save.pop()-'0');
			y=(save.pop()-'0');
			z=((x*y) % 10);
			char c=z+'0';
		save.push(c);
		i++;
		//cout<<"sec *"<<endl;
		}
		if ((b[i] >= '0') && (b[i] <= '9'))
		{ 
		//x=b[i];
		save.push(b[i]);
		i++;
		//cout<<"num"<<endl;
		}
		if(b[i] =='^')
		{
			x=(save.pop()-'0');
			y=(save.pop()-'0');
			z=1;
			for(j=0;j<x;j++)
			{
				z=z*y;
			}
			z=(z % 10);
			char c=z+'0';
		save.push(c);
		i++;
		//cout<<"third ^"<<endl;
		}
    }
cout<<" "<<save.pop() <<endl;
cout<<endl;
}
return 0;	
}
