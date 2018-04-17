#include<iostream>
using namespace std;
/*struct quick
{
	int count=0;
	int s[50]={NULL};
};
struct quick temp1,temp2,temp3;*/
int partition(int a[], int l, int r,int &count)
  { 
  //int c=0;
  	int i = l-1;
	 int v = a[r];
    for (int j=l;j<r-1;j++)
      {
      	count++;
        if(a[j]<v)
        {
        	i++;
        	int temp=a[i];
        	a[i]=a[j];
        	a[j]=a[i];
		}
      }
    int temp1=a[i+1];
	a[i+1]=a[r];
	a[r]=temp1;
	return i+1;
  }

int quicksort(int a[], int l, int r)
  {
  	int count=0;
    if (r <= l) 
	return 0;
   /* call for partition function that you modify */
   int i=partition(a,l,r,count);
    count+=quicksort(a, l, i-1);
    count+=quicksort(a, i+1, r);
    return count;
  }
 

  
  int main()
  {
  	int a[50];
  	int N;
  	cout<<"enter number of elements to sort"<<endl;
  	cin>>N;
  	cout<<"enter "<<N<<" elements"<<endl;
  	for(int i=0;i<N;i++)
  	{
  		cin>>a[i];
	}
	cout<<endl;
	int count=0;
	count=quicksort(a,0,N-1);
	cout<<"sorted array is"<<endl;
	for(int i=0;i<N;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<"num of comparisions "<<count<<endl;
	return 0;
  }

