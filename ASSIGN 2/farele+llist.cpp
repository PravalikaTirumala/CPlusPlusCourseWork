	#include<iostream>
#include<stdio.h>
using namespace std;

class llist
{
	struct node				//declaring structure with the required data and a link to next node
	{
		int element;
		int farelement;
		node* next;
	};
	
	private:
	node* head;
	
	public:
		llist()
		{
			head =NULL;
		}
	
		void create_list(int element_,int farelement_)
		{
		node *nnode=new node();			//allocating memory for new node
		nnode->element=element_;		
		nnode->farelement=farelement_;
		nnode->next=head;				//after assigning values head will move to the next node
		head=nnode;						//at the end head will be pointed to the last node
		}
		
		void print_list()
		{
		node *temp=head;			// temporary pointer of type node
		if(temp==NULL)
		{
			cout<<"list is empty"<<endl;
			return;
		}
		else if(temp->next==0)
		{
		cout<<"("<<temp->element<<","<<temp->farelement<<")"<<" ";	
		}
		else
		{
			do
			{
			cout<<"("<<temp->element<<","<<temp->farelement<<")"<<" ";
			temp=temp->next;	
			}while(temp!=NULL);
		}
		}
};
	int main()
	{
		int a[20],i,j,diff,temp,index;
		llist ll;
		//node* nn=new node(20);
		cout<<"enter 20 array element"<<endl;
		for(i=0;i<20;i++)
		{
			cin>>a[i];
		}
		cout<<"array elements are"<<endl;
		for(j=0;j<20;j++)
		{
			cout<<a[j]<<" ";
		}
		
		for(i=0;i<20;i++)
		{
			temp=0;
			for(j=0;j<20;j++)
			{
				if(a[i]<a[j])
				diff=a[j]-a[i];
				else
				diff=a[i]-a[j];
				if(diff>temp)
				{
					temp=diff;
					index=j;
				}
			//nn.element[i]=a[i];
			//nn.farelement[i]=index;
			}
			ll.create_list(a[i],a[index]);
		}
		
		ll.print_list();
		system("pause");
		return 0;
	}

