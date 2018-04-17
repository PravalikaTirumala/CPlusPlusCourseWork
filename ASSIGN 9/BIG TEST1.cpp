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
	int c=0;
	int s[50]={NULL};
};

struct sort t,temp1,temp2,temp3;
int i,j,first,last,a_ele;

sort bubble_sort_modified(int a[],int f,int l)
{
	
	int i,j,temp=0,count=0,num_cmp=0;
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
	cout<<"bub cmp"<<num_cmp;
	for(i=f;i<l;i++)
	{
		//cout<<a[i]<<" ";
	t.s[i]=a[i];
	}
	return t;
}

sort sel_sort(int a[],int f,int l)
{
	
	int i,j,temp=0,num_cmp=0;
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
	cout<<"sel cmp"<<num_cmp;
	for(i=f;i<l;i++)
	{
	t.s[i]=a[i];
	}
	return t;
}

sort insertion_sort(int a[],int f,int l)
{

	int i=f,j=i+1,temp=0,num_cmp=0;
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
	cout<<"ins cmp"<<num_cmp;
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
	cout<<"sorted array is:"<<endl;																					
	for(i=0;i<a_ele;i++)
	{
	cout<<aa[i]<<" ";
	}
	cout<<endl;
	return aa;
}

int main()																					
{
//first=0;
//last=a_ele-1;																						
int ins_count,sel_count,modi_count,ratio_cmp;
int r1,r2;
int *disp1, *disp2, *arr;	
//int arr[50];
char ch;
	cout<<endl;
	cout<<endl;
	cout<<"-----comparisions of the sorts-----"<<endl;
	cout<<endl;
	cout<<endl;
cout<<"enter a charater to perform an operation or E to exit"<<endl;
cin>>ch;
while(ch != 'Z')
{
switch(ch)
	{
	case 'A':
		arr=create_array();
		temp1=sel_sort(arr,0,a_ele);
		temp2=insertion_sort(arr,0,a_ele);
		r1=temp1.c;
		r2=temp2.c;
		ratio_cmp=r1/r2;
		cout<<"1----- SELECTION sort:-----"<<endl;
			disp_array(temp1.s);
			cout<<"num of comparisons-"<<temp1.c<<endl;
		cout<<"2-----INSERTION SORT:-----"<<endl;	
			disp_array(temp2.s);
			cout<<"num of comparisons-"<<temp2.c<<endl;
		cout<<"---ratio of comparisions---"<<" "<<ratio_cmp<<endl;
			break;
	case 'B':
		arr=create_array();
		temp1=sel_sort(arr,0,a_ele);
		temp2=bubble_sort_modified(arr,0,a_ele);
		ratio_cmp=temp1.c/temp2.c;
		cout<<"1----- SELECTION SORT:-----"<<endl;
			disp_array(temp1.s);
			cout<<"num of comparisons-"<<temp1.c<<endl;
		cout<<"2----- MODIF BUBBLE SORT:-----"<<endl;
			disp_array(temp2.s);
			cout<<"num of comparisons-"<<temp2.c<<endl;	
		cout<<"---ratio of comparisions---"<<" "<<ratio_cmp<<endl;
		break;
	case 'C':
		arr=create_array();
		temp1=insertion_sort(arr,0,a_ele);
		temp2=sel_sort(arr,0,a_ele);
		ratio_cmp=temp1.c/temp2.c;
		cout<<"1----- INSERTION SORT:-----"<<endl;
			disp_array(temp1.s);
			cout<<"num of comparisons-"<<temp1.c<<endl;
		cout<<"2----- SELECTION SORT:-----"<<endl;
			disp_array(temp2.s);
			cout<<"num of comparisons-"<<temp2.c<<endl;
		cout<<"---ratio of comparisions---"<<" "<<ratio_cmp<<endl;
		break;
	case 'D':
		arr=create_array();
		temp1=insertion_sort(arr,0,a_ele);
		temp2=bubble_sort_modified(arr,0,a_ele);
		ratio_cmp=temp1.c/temp2.c;
		cout<<"1----- INSERTION SORT:-----"<<endl;
		disp_array(temp1.s);
			cout<<"num of comparisons-"<<temp1.c<<endl;
		cout<<"2----- MODIF BUBBLE SORT SORT:-----"<<endl;
			disp_array(temp2.s);
			cout<<"num of comparisons-"<<temp2.c<<endl;
		cout<<"---ratio of comparisions---"<<" "<<ratio_cmp<<endl;
		break;
	case 'E':
		arr=create_array();
		temp2=insertion_sort(arr,0,a_ele);
		temp1=bubble_sort_modified(arr,0,a_ele);
		ratio_cmp=temp1.c/temp2.c;
		cout<<"1----- INSERTION SORT:-----"<<endl;
			disp_array(temp1.s);
			cout<<"num of comparisons-"<<temp1.c<<endl;
		cout<<"2----- MODIF BUBBLE SORT:-----"<<endl;
			disp_array(temp2.s);
			cout<<"num of comparisons-"<<temp2.c<<endl;
		cout<<"---ratio of comparisions---"<<" "<<ratio_cmp<<endl;
		break;
	case 'F':
		arr=create_array();
		temp1=bubble_sort_modified(arr,0,a_ele);
		temp2=sel_sort(arr,0,a_ele);
		ratio_cmp=temp1.c/temp2.c;
		cout<<"1----- MODIF BUBBLE SORT:-----"<<endl;
			disp_array(temp1.s);
			cout<<"num of comparisons-"<<temp1.c<<endl;
		cout<<"2----- SELECTION SORT:-----"<<endl;
			disp_array(temp2.s);
			cout<<"num of comparisons-"<<temp2.c<<endl;
		cout<<"---ratio of comparisions---"<<" "<<ratio_cmp<<endl;
		break;
	 default:
	  	cout<<"invalid input"<<endl;
	}
	cout<<endl<<endl;
	 cout<<"enter a character to perform an operation or E to exit"<<endl;
	  cin>>ch;
}
return 0;
}



