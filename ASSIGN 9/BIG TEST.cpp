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
	int s[50];
};

struct sort t,temp1,temp2,temp3;
int i,j,first,last,a_ele;

sort bubble_sort_modified(int a[],int f,int l)
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
	t.c=num_cmp;
	for(i=f;i<l;i++)
	{
	t.s[i]=a[i];
	}
	return t;
}

sort sel_sort(int a[],int f,int l)
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
	t.c=num_cmp;
	for(i=f;i<l;i++)
	{
	t.s[i]=a[i];
	}
	return t;
}

sort insertion_sort(int a[],int f,int l)
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
	t.c=num_cmp;
	for(i=f;i<l;i++)
	{
	t.s[i]=a[i];
	}
	return t;
}
int *create_array()
{
	static int a[50];
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
int *disp_array(int aa[])
{																						
	for(i=0;i<a_ele;i++)
	{
	cout<<aa[i]<<" ";
	}
	cout<<endl;	
	return aa;
}

int main()																					
{
first=0;
last=a_ele-1;																						
int ins_count,sel_count,modi_count,ratio_cmp;
int *disp1, *disp2, *arr;	
//int arr[50];
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
		temp1=sel_sort(arr,first,last);
		temp2=insertion_sort(arr,first,last);
		ratio_cmp=temp1.c/temp2.c;
			cout<<"SELECTION SORT:"<<endl;
			disp1=disp_array(temp1.s);
			cout<<"sorted array-"<<disp1<<endl;
			cout<<"num of comparisons-"<<temp1.c<<endl;
			
			cout<<"INSERTION SORT:"<<endl;
			disp2=disp_array(temp2.s);
			cout<<"sorted array-"<<disp2<<endl;
			cout<<"num of comparisons-"<<temp2.c<<endl;
		break;
	case 'B':
		arr=create_array();
		temp1=sel_sort(arr,first,last);
		temp2=bubble_sort_modified(arr,first,last);
		ratio_cmp=temp1.c/temp2.c;
			cout<<"SELECTION SORT:"<<endl;
			disp1=disp_array(temp1.s);
			cout<<"sorted array-"<<disp1<<endl;
			cout<<"num of comparisons-"<<temp1.c<<endl;
			
			cout<<"MODIF BUBBLE SORT:"<<endl;
			disp2=disp_array(temp2.s);
			cout<<"sorted array-"<<disp2<<endl;
			cout<<"num of comparisons-"<<temp2.c<<endl;	
		break;
	case 'C':
		arr=create_array();
		temp1=insertion_sort(arr,first,last);
		temp2=sel_sort(arr,first,last);
		ratio_cmp=temp1.c/temp2.c;
			cout<<"INSERTION SORT:"<<endl;
			disp1=disp_array(temp1.s);
			cout<<"sorted array-"<<disp1<<endl;
			cout<<"num of comparisons-"<<temp1.c<<endl;
			
			cout<<"SELECTION SORT:"<<endl;
			disp2=disp_array(temp2.s);
			cout<<"sorted array-"<<disp2<<endl;
			cout<<"num of comparisons-"<<temp2.c<<endl;
		break;
	case 'D':
		arr=create_array();
		temp1=insertion_sort(arr,first,last);
		temp2=bubble_sort_modified(arr,first,last);
		ratio_cmp=temp1.c/temp2.c;
			cout<<"INSERTION SORT:"<<endl;
			disp1=disp_array(temp1.s);
			cout<<"sorted array-"<<disp1<<endl;
			cout<<"num of comparisons-"<<temp1.c<<endl;
			
			cout<<"MODIF BUBBLE SORT SORT:"<<endl;
			disp2=disp_array(temp2.s);
			cout<<"sorted array-"<<disp2<<endl;
			cout<<"num of comparisons-"<<temp2.c<<endl;
		break;
	case 'E':
		arr=create_array();
		temp2=insertion_sort(arr,first,last);
		temp1=bubble_sort_modified(arr,first,last);
		ratio_cmp=temp1.c/temp2.c;
			cout<<"INSERTION SORT:"<<endl;
			disp1=disp_array(temp1.s);
			cout<<"sorted array-"<<disp1<<endl;
			cout<<"num of comparisons-"<<temp1.c<<endl;
			
			cout<<"MODIF BUBBLE SORT:"<<endl;
			disp2=disp_array(temp2.s);
			cout<<"sorted array-"<<disp2<<endl;
			cout<<"num of comparisons-"<<temp2.c<<endl;
		break;
	case 'F':
		arr=create_array();
		temp1=bubble_sort_modified(arr,first,last);
		temp2=sel_sort(arr,first,last);
		ratio_cmp=temp1.c/temp2.c;
			cout<<"MODIF BUBBLE SORT:"<<endl;
			disp1=disp_array(temp1.s);
			cout<<"sorted array-"<<disp1<<endl;
			cout<<"num of comparisons-"<<temp1.c<<endl;
			
			cout<<"SELECTION SORT:"<<endl;
			disp2=disp_array(temp2.s);
			cout<<"sorted array-"<<disp2<<endl;
			cout<<"num of comparisons-"<<temp2.c<<endl;
		break;
	 default:
	  	cout<<"invalid input"<<endl;
	}
	 cout<<"enter an operation to perform or E to exit"<<endl;
	  cin>>ch;
}
return 0;
}


