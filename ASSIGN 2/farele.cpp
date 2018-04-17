#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct far_element
{
	int value;
	int distance;
};
int main()
{
	int i,j,max,ind,a[20],diff;
	far_element* fe=new far_element[20];
	cout<<"enter 20 elements in to array"<<endl;
	for(i=0;i<20;i++)
	{
		cin>>a[i];
	}
	cout<<"array elements are"<<endl;
	for(j=0;j<20;j++)
	{
		cout<<a[j]<<" ";
	}
	for(i=0;i<20;i++)
	{
		max=0;
		for(j=0;j<20;j++)
		{
			if(a[i]<=a[j])
			diff=a[j]-a[i];
			else
			diff=a[i]-a[j];
	
			if (diff > max )
			{
				max= diff;
				ind=j;
			}
		}
		fe[i].value=a[i];
		fe[i].distance=a[ind];
	}
	for(i=0;i<20;i++)
	{
		cout<<"("<<fe[i].value<<","<<fe[i].distance<<")  ";
	}
	return 0;
}


