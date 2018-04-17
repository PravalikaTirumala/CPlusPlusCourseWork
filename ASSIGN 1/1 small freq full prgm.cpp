#include<iostream>
using namespace std;

int main()
{
	int a[20],val[20],countarr[20];
	int i;
	int count;
	int fcount=20;

	cout<<"enter integer numbers in to the array"<<endl;
	for (int i=0;i<20;i++)
	{
	cin>>a[i];
	}
	cout<<"array elements are"<<endl;
	for(int j=0;j<20;j++)
	{
	cout<<a[j]<<" ";
    }
    cout<<"lowest frequencies of the numbers is"<<endl;
    for(i=0;i<20;i++)
    	{
    		count=0;
      		for(int j=0;j<20;j++)
    		{
    			if(a[i]==a[j])
    			count=count+1;
    			
    		}
    		val[i]=a[i];
    		countarr[i]=count;
    		if(count<fcount)	
    		{
    			fcount=count;
   			}
		}
	for(int k=0;k<20;k++)
		{
			if(countarr[k]==fcount)
			{
			cout<<"the interger"<<" "<<val[k]<<" "<<"occurs with less frequency of"<<" "<<fcount<<" "<<"times"<<endl;
			}
		}
	return 0;
}

