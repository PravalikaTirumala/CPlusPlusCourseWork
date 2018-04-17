/*find an array for each case such that function A outperforms function B 
(i.e. number of comparisons function A performs / number of comparisons function B 
performs is minimized: the smaller this number higher your score

a)	A=Selection Sort, B=Insertion Sort
b)	A=Selection Sort, B=Modified Bubble Sort
c)	A=Insertion Sort, B=Selection Sort
d)	A=Insertion Sort, B=Modified Bubble Sort
e)	A=Modified Bubble Sort, B=Insertion Sort
f)	A=Modified Bubble Sort, B=Selection Sort
*/
#include<iostream>
using namespace std;
struct sort
{
	int c;
	int s[];
};
typedef sort* temp;
/*sort bubble_sort(int a[],int f,int l)
{
	link temp
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
	temp.c=num_cmp;
	temp.s=a;
	//cout<<"Number of comparisions required "<<num_cmp<<endl;
	return temp;
}*/
sort bubble_sort_modified(int a[],int f,int l)
{
	link temp;
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
	temp.c=num_cmp;
	temp.s=a;
	return temp;
	//cout<<"number of comparisions required are"<<num_cmp<<endl;
	//return num_cmp;
}

sort sel_sort(int a[],int f,int l)
{
	link temp;
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
	//cout<<"number of comparisions required are"<<num_cmp<<endl;
	//int num_cmp
	temp.c=num_cmp;
	temp.s=a;
	return temp;
}

sort insertion_sort(int a[],int f,int l)
{
	link temp;
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
	//cout<<"number of comparieions required are"<<num_cmp<<endl;
	//return num_cmp; 
	temp.c=num_cmp;
	temp.s=a;
	return temp;
}
int *create_array()
{
	static int a[a_ele];
	cout<<"enter how many elements you want for an array:"<<endl;
	cin>>a_ele;
	cout<<"enter some elements"<<endl;
	cout<<endl;
		for(i=0;i<a_ele;i++)
			{
			cin>>a[i];
			}
	return a;
}
int *disp_array(int b[],int num_ele)
{
for(i=0;i<num_ele;i++)
	{
	cout<<b[i]<<" ";
	}
	cout<<endl;	
return b;
}

int main()
{
int ins_count,sel_count,modi_count,ratio_cmp;
int *arr, *disp;	
char ch;
	cout<<endl;
	cout<<endl;
	cout<<"-----comparisions of the sorts-----"<<endl;
cout<<"enter a charater to perform an operation"<<endl;
cin>>ch;
while(ch != 'Z')
{
switch(ch)
	{
	case 'A':
		arr=create_array();
		sel_count=sel_sort(arr,first,last);
		ins_count=insertion_sort(arr,first,last);
		ratio_cmp=sel_count/ins_count;
		disp=disp_array()
		cout<<"sorted array is:"<<
		cout<<""
		break;
	case 'B':
		sel_count=sel_sort(b,first,last);
		modi_count=bubble_sort_modified(b,first,last);
		ratio_cmp=sel_count/modi_count;
		break;
	case 'C':
		ins_count=insertion_sort(b,first,last);
		sel_count=sel_sort(b,first,last);
		ratio_cmp=ins_count/sel_count;
		break;
	case 'D':
		ins_count=insertion_sort(b,first,last);
		modi_count=bubble_sort_modified(b,first,last);
		ratio_cmp=ins_count/modi_count;
		break;
	case 'E':
		ins_count=insertion_sort(b,first,last);
		modi_count=bubble_sort_modified(b,first,last);
		ratio_cmp=modi_count/ins_count;
		break;
	case 'F':
		modi_count=bubble_sort_modified(b,first,last);
		sel_count=sel_sort(b,first,last);
		ratio_cmp=modi_count/sel_count;
		break;
	}
}

int i,j,first,last,a_ele;
	
	int b[50];
	
		first=0;
		last=a_ele-1;
		cout<<endl;
	
	bubble_sort(b,first,last);
	
	
	for(i=0;i<a_ele;i++)
	{
	cout<<b[i]<<" ";
	}
	cout<<endl;
		
return 0;
}


