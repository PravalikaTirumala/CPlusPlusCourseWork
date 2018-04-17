#include<iostream>

using namespace std;
static const int n = 1000;      /* vector size limit */

class llist
{
	public:
	struct node
	{
	int x;    /* original index of non-zero array element */
	int val;
	node* next; /* integer non-zero value at index x */
	};
	private:
		node* head;
	public:
		llist()
		{
			head =NULL;
		}
node* row=new node[n];
node* col=new node[n];

void generate_row_and_col() 
	{
	int i;

	for (i = 1; i <= n / 4; i++) 
	{ 
		row[i].x = 4 * i; row[i].val = (4 * i) % 3+2; 
	}
	row[0].x = 0; row[0].val = 1;
	row[n / 4].x = -1;
	
	for(i=0;i<=n/4;i++)
	{
		row->x=row[i].x;
		row->val=row[i].val;
		row->next=head;
		head=row;
		cout<<"("<<row->x<<","<<row->val<<")"<<" ";
	}
	cout<<endl;
	cout<<endl;
	for (i = 1; i <= n / 5; i++) 
	{
		 col[i].x = 5 * i; 
		 col[i].val = (5 * i) % 3+2; 
	}
	col[0].x = 0; col[0].val = 1;
	col[n / 5].x = -1;
	for(i=0;i<=n/4;i++)
	{
		col->x=col[i].x;
		col->val=col[i].val;
		col->next=head;
		head=col;
		cout<<"("<<col->x<<","<<col->val<<")"<<" ";
	}

	}
		
	int dotproduct()
	{
	double sum=0;
	int i = 0, j = 0;
	row=head;
	col=head;
	while ( (row->x != -1) && (col->x != -1))
	{
		if (row->x == col->x) 
		{
		    sum += (row->val) * (col->val);
			row=row->next,col=col->next;
		}
		else if (row->x < col->x)
		{
			row=row->next;
	    }
		else
		{
			col=col->next;
		}
	}

	cout << "Dot product is " << sum << "\n";
	return 0;
	}

};



int main()
{
	llist l1;
	l1.generate_row_and_col();
	l1.dotproduct();
	return 0;

}

