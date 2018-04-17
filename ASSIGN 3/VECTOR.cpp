#include<iostream>
#include<stdio.h>
using namespace std;

static const int n=4;
int i,j,a1[n],a2[n],vec_prod;

int vector_product();


struct vec_elements
{
	int index;
	int element;
} ;
//vec_elements v1[n];

vec_elements* v1=new vec_elements[n];
vec_elements v2[n];



vec_elements rows_cols1()
{
	for(i=0;i<n;i++)
	{
		if(a1[i]==0)
		{
		continue;
		}
		v1[i].index=i;
		v1[i].element=a1[i];
	}
	cout<<endl;
	cout<<"first vector with non zero elements along with index"<<endl;
	for(i=0;i<n;i++)
	{
		if(v1[i].element==0)
		{
		continue;	
		}
	cout<<v1[i].index<<","<<v1[i].element<<" ";
	}
	return v1[i];
}
vec_elements rows_cols2()
{
	for(i=0;i<n;i++)
	{
		if(a2[i]==0)
		{
			continue;
		}
		v2[i].index=i;
		v2[i].element=a2[i];		
	}
	cout<<endl;
	cout<<"second vector with non zero elements along with index"<<endl;
	for(i=0;i<n;i++)
	{
	if(v2[i].element==0)
	{
	continue;	
	}
	cout<<v2[i].index<<","<<v2[i].element<<" ";
	}
	return v2[i];
}

int vector_product()
{
	
	i=0,j=0,vec_prod=0;
	while(i<n && j<n)
	{
		if(v1[i].index==v2[j].index)
		{
		vec_prod += (v1[i].element * v2[j].element);
		i++,j++;	
		}
		else if(v1[i].index < v2[j].index)
			i++;
		else
			j++;
	}
	cout<<"product is:"<<vec_prod<<endl;
	//return 0;
}
int main()
{
	
	cout<<"enter first victor elements of your choice"<<endl;
	for(i=0;i<n;i++)
	{
	cin>>a1[i];
	}
cout<<"vector 1 elemens are"<<endl;
	for(i=0;i<n;i++)
	{
	cout<<a1[i]<<" ";
	}
	cout<<endl;
cout<<"enter second vector elements of your choice"<<endl;
	for(j=0;j<n;j++)
	{
	cin>>a2[j];
	}
	cout<<endl;
cout<<"vector 2 elemens are"<<endl;
	for(j=0;j<n;j++)
	{
	cout<<a2[j]<<" ";
	}
	cout<<endl;
rows_cols1();
rows_cols2();
vector_product();

  return 0;
}







