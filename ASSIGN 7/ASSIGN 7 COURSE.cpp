/*Write a C++ program that creates a queue of up to 100 integers, 
and then it does the following on user's input (your program must check 
for conditions: e.g. no get when the queue is empty):

P x: puts x into queue
G :  outputs the element at the head of the queue, and removes this element
 from the queue
E :  outputs "empty" if queue is empty; otherwise "not empty" 
F :  displays the entire content of the queue in first-in first-out order; 
no change in the queue  
*/
#include<iostream>
#include<stdio.h>
using namespace std;

class QUEUE 
  {
	private:
	struct node 
	{
	int item;
	node* next; 
		node(int x) 
		{
		item = x; next = 0;
		} 
    };
	typedef node *link;
	link head, tail;
	public:
	QUEUE(int)
	{
	head = 0;
	}
	int empty() const
		{
		if(head == 0)
		cout<<"queue is empty"<<endl;
		else
		cout<<"not empty"<<endl;
		return 0;
	
		}
	void put(int x)
	{
	link t = tail;//point t to node where tail is pointing 
	tail = new node(x);//point tail to new node
	if (head == 0) //if there is no list previously then make the newly
	head = tail; //created node as head and tail
	else t->next = tail;// else attach existing link to new node
    }
	int get()
	{
		if(head==0)
		{
			cout<<"nothing to get; queue is empty  "<<endl;
			return 0;
		}
		else
		{
		int v = head->item;
		link t = head->next;
		delete head;
		head = t;
		return v;
		}
	}
	void peekAll() //display all the elements in the queue. 
	//The elements stay in the queue after this operation.
	{ 
		if(head==0)
		cout<<"nothing to peek; queue is empty "<<endl;
		else
		{
		link t=head;
		cout<<"elementa of the queue in lifo order is:"<<endl;
		while(t != NULL)
		{
		cout<<t->item<<" ";
		t=t->next;
		}
		}
    }

};

int main()
{
	QUEUE q(100);
	char ch;
	int a;
	cout<<"enter operation or z/Z to exit"<<endl;
	cin>>ch;
	while(ch != 'Z')
	{
		switch(ch)
		{
		case 'P':
			///cout<<"This function inserts an element in to the queue"<<endl;
			cout<<"enter element"<<endl;
			cin>>a;
			q.put(a);
			break;
		case 'G':
			//cout<<"This function outputs value at head node and deletes it"<<endl;
			cout<<q.get();
			cout<<endl;
			//cout<<a;
			break;
		case 'E':
		//	cout<<"This functions checks for the number of elements"<<endl;
			q.empty();
			break;
		case 'F':
			//cout<<"This function displays values in FIFO order"<<endl;
			q.peekAll();
			cout<<endl;
			break;
		default:
			cout<<"invalid input"<<endl;
		}
		cout<<"enter operation or z/Z to exit"<<endl;
		cin>>ch;
	}
	return 0;
}

