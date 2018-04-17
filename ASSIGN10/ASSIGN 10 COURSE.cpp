#include<iostream>
using namespace std;
void exch(int &x, int &y) 
{
int temp = 0;
	temp = x;
	x = y;
	y = temp;
}



int partition(int a[], int l, int r, int &count) 
{ 
int i = l - 1; int j = r; int v = a[r];
	for (;;) 
	//{
	while ((a[++i] < v) && a[i]>v)
		{
			count++;         
		}
	/*if (a[i]>v) 
		{ 
		count++; 
		}*/
	while (v < a[--j])
		{
		count++;         
		if (j == l) 
		{
		 break;
	 	}
		}
	if (v>a[j]) 
	{ count++; 
	}
	if (i >= j) 
	{
	 break; 
	}
	exch(a[i], a[j]);
	//}
	exch(a[i], a[r]);
	return i;

}

int quicksort(int a[], int l, int r)
{
	int count = 0;
	if (r <= l) 
	{
	 return 0;
	 }
	int i = partition(a, l, r, count);
	count += quicksort(a, l, i - 1);
	count += quicksort(a, i + 1, r);
	return count;
}



int main() 

{

	

	int Array[50];

	int N;



	cout << "Enter the number of elements : ";

	cin >> N;



	cout << "Enter the array elements : ";

	for (int i = 0; i < N; i++)

	{

		cin >> Array[i];

	}



	cout << endl;

	int count = 0;



	count = quicksort(Array, 0, N - 1);



	cout << "Sorted Array " << endl;

	for (int i = 0; i < N; i++)

	{

		cout << Array[i] << " ";

	}

	cout << endl << endl;

	cout << "Total number of comparisons : " << count << endl << endl;

return 0;
}
