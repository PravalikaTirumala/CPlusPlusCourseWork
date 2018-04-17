#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int a[20];
	int valarr[20];
	int i,j,k,disele;
	cout<<"enter 20 elements"<<endl;
	for(i=0;i<20;i++)
	{
		cin>>a[i];
	}
		cout<<"array elemnts are"<<endl;
		for(j=0;j<20;j++)
		{
		cout<<a[j]<<" ";
		}
		
	cout<<"distinct elements are"<<endl;		
	for(i=0;i<20;i++) 
		{
  		for (j=0;j<i;j++)
			{
      		if (a[i]==a[j]) //if the elements are equal then exit the loop
       		break;	//come out of loop
      	    }
      	  if(i==j) // if the index is same then print the element
	  	  {
      	  cout<<a[i]<<" ";
  	  	  }
  	    }
		
	return 0;
}
