/*1.	Modify as necessary both functions (merge and mergesort) such that mergesort returns the total number of comparisons that have performed 
in sorting a given array a. In these comparisons, only the comparisons that involve array elements are counted. You are not allowed to use any 
global variable in counting these comparisons. You may want to add new parameters to functions and/or make functions return integer values.

2.	Write a C++ program that receives as input an array of integers and calls mergesort to sort this array. Output must include the final sorted
 array and number of comparisons performed as described in Item 1 above.*/

#include<iostream>
using namespace std;
struct sort
{
	int c=0;
	int s[50]={NULL};
};
struct sort temp,temp2,temp3,temp4;
int merge(int a[], int l, int m, int r)
  { 
  int cou=0;
  	int i, j;
  	    static int aux[50];
    	for (i = m+1; i > l; i--) 
		{
		aux[i-1] = a[i-1];
		}
    	for (j = m; j < r; j++) 
		{
		aux[r+m-j] = a[j+1];
		//cout<<"2"<<endl;
		}
    	for (int k = l; k <= r; k++)														
	  	 {
	  	
		  if (aux[j] < aux[i])
		{
		a[k] = aux[j--]; 
		cou++;
		}
		else 
		{
		a[k] = aux[i++];
		cou++;
		
		}
	}
	/*temp.c=cou;
	for (int k = l; k <= r; k++)	
	{
		temp.s[i]=a[i];
	}
	
	return temp;*/
	return cou;		
  }

sort mergesort(int a[], int l, int r)
  { 
 int count;
  	if (r > l) 
		{
		int m = (r+l)/2;
    	mergesort(a, l, m); 
    	mergesort(a, m+1, r);
    	count=count+merge(a, l, m, r);
		//count=temp2.c+count;
		/*for (int k = l; k <= r; k++)
		{
	temp3.s[k]=temp2.s[k];
		}*/	
  }
else
{
}
for (int k = l; k <= r; k++)
		{
	temp3.s[k]=a[k];
		}
temp3.c=count;
  return temp3;
}
  
  int main()
{
	int i,j;
	int count=0;
	int first_ind,last_ind,a_ele;
	int a[50];
	cout<<"enter how many elements you want for an array:"<<endl;
	cin>>a_ele;
	cout<<"enter some elements"<<endl;
	cout<<endl;
		for(i=0;i<a_ele;i++)
			{
			cin>>a[i];
			}
		first_ind=0;
		last_ind=a_ele-1;
	cout<<endl;
	temp4=mergesort(a,first_ind,last_ind);
	for(i=0;i<a_ele;i++)
	{
	cout<<temp4.s[i]<<" ";
	}
	cout<<"number of comparisions are"<<temp4.c<<endl;
	cout<<endl;
	cout<<endl;
return 0;
}


  
  

