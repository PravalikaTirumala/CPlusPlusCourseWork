 #include<iostream>
using namespace std;

int merge(int a[], int l, int m, int r)
  { 
  int count=0;

  	int i, j;
    static int aux[50];
    for (i = m+1; i > l; i--) 
	aux[i-1] = a[i-1];
    for (j = m; j < r; j++)
	 aux[r+m-j] = a[j+1];
    for (int k = l; k < r; k++)
       {
	   if (aux[j] < aux[i])
          a[k] = aux[j--]; 
		  else a[k] = aux[i++];
		}
		return count;
  }
 
void mergesort(int a[], int l, int r)
  { 
  int c;
  	if (r <= l) 
	return;
		else
		{
		int m = (r+l)/2;
    	mergesort(a, l, m); 
    	mergesort(a, m+1, r);
    	c=c+merge(a, l, m, r);
    	cout<<"number of comparisions are"<<c*(r-1)<<endl;
    	}
    	
  }
 int main()
{
	int i,j;
//int count=0;
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
	mergesort(a,first_ind,last_ind);
	for(i=0;i<a_ele;i++)
	{
	cout<<a[i]<<" ";
	}
	//cout<<"number of comparisions are"<<c<<endl;
	//cout<<count;
	cout<<endl;
	cout<<endl;
return 0;
}

