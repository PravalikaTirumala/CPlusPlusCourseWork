#include<iostream>
using namespace std;

void bubble_sort(int a[],int f,int l)
{
	cout<<endl;
	cout<<endl;
	cout<<"BUBBLE SORT :"<<endl;
	int i,j,temp,count,num_cmp=0;
	for(i=f;i<l;i++)
	{
		count=0;
		for(j=f;j<l;j++)
		{
			num_cmp++;
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	cout<<"Number of comparisions required "<<num_cmp<<endl;
}
void bubble_sort_modified(int a[],int f,int l)
{
	cout<<endl;
	cout<<endl;
	cout<<"MODIFIED BUBBLE SORT :"<<endl;
	int i,j,temp,count,num_cmp=0;
	for(i=f;i<l;i++)
	{
		count=0;
		for(j=f;j<l;j++)
		{
			num_cmp++;
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				count++;
			}
		}
		if(count==0)
		{
		cout<<"no more comparisions are req, can exit the outer loop too"<<endl;
		break;
		}
	}
	cout<<"number of comparisions required are"<<num_cmp<<endl;
}

void sel_sort(int a[],int f,int l)
{
	cout<<endl;
	cout<<endl;
	cout<<"SELECTION SORT :"<<endl;
	int i,j,temp,num_cmp=0;
	for(i=f;i<l;i++)
	{
		int min=i;
		for(j=i+1;j<l;j++)
		{
		num_cmp++;
		if(a[j]<a[min])
			{
				min=j;
			}
		}
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}	
	cout<<"number of comparisions required are"<<num_cmp<<endl;
}

void insertion_sort(int a[],int f,int l)
{
	cout<<endl;
	cout<<endl;
	cout<<"INSERTION SORT :"<<endl;
	int i=f,j=i+1,temp,num_cmp=0;
	num_cmp++;
	if(a[i]>a[j])
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
	for(i=f+2;i<l;i++)
	{
		for(j=i-1;j>1;j--)
		{
			num_cmp++;
			if(a[i]<a[j])
				{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
				}
		}
	}
	cout<<"number of comparieions required are"<<num_cmp<<endl; 
}

int main()
{
	int i,j,first,last,a_ele;
	int b[50];
	cout<<"enter how many elements you want for an array:"<<endl;
	cin>>a_ele;
	cout<<"enter some elements"<<endl;
	cout<<endl;
		for(i=0;i<a_ele;i++)
			{
			cin>>b[i];
			}
		first=0;
		last=a_ele-1;
		cout<<endl;
	cout<<"array elements to be sorted are:"<<endl;
		for(j=0;j<a_ele;j++)
			{
			cout<<b[j]<<" ";
			}
	cout<<endl;

	bubble_sort(b,first,last);
	for(i=0;i<a_ele;i++)
	{
	cout<<b[i]<<" ";
	}
	cout<<endl;
	
	
	bubble_sort_modified(b,first,last);
	for(i=0;i<a_ele;i++)
	{
	cout<<b[i]<<" ";
	}
	cout<<endl;
	
	
	sel_sort(b,first,last);
	for(i=0;i<a_ele;i++)
	{
	cout<<b[i]<<" ";
	}
	cout<<endl;
	
	
	insertion_sort(b,first,last);
	for(i=0;i<a_ele;i++)
	{
	cout<<b[i]<<" ";
	}
	cout<<endl;
return 0;
}


