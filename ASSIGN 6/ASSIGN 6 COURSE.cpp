#include<iostream>
using namespace std;
class STACK 
  {
private:
	struct node 
	{
	void* item;
	node* next; 
	node(void x, node* t) 
	{
	item = x;
	next = t;
	} 
	};
typedef node *link;
link head;
public:
	STACK(int)
	{
	head = 0;
	}
	int empty() const
	{
		if(head==0)
		cout<<"stack is empty"<<endl;
		else
		cout<<"not empty"<<endl;
		return 0;
	}
	void push(void x)
	{
	head = new node(x, head);
	}
	int peek() 
    {
        if(head==0)
		cout<<"there are no elements"<<endl; /* implement this part */
		else
		cout<<head->item<<endl;
    }
	int pop()
	{
	if(head==0)
	cout<<"nothing to pop off, stack is empty"<<endl;
	else
	{
	int v = head->item;
	link t = head->next;
	delete head;
	head = t;	
	cout<<v;
	}
	return 0;
	}
	void flush()
      { 
      link t;
      /*while(head->next != 0)
      {
      	int a=head->item;
      	cout<<a<<" ";
      	t=head->next;
      	delete head;
      	head=t;
      }
	  head=head->next;
	  int b=t->item;
	  cout<<b<<endl;
	  delete t;
	  cout<<head->item<<" ";
	  head=0;*/
	  while(head->next != 0)
	  {
	  	t= head;
	  	cout<<t->item<<" ";
	  	head=head->next;
	  }
	  cout<<t->item;
	  delete t;
	  head=0;
      } 
  };
int main()
  {
  	STACK s1(100);
  	int y;
	char ch;
  cout <<"Enter operation or Z to exit:";
  cin>>ch;

  while (ch!='Z')
  {
    switch (ch)
    {
    case 'P' : 
      cin >> y;
      s1.push(y);
      break;
    case 'R' :
      s1.pop();
      break; 
    case 'E':
      s1.empty();
      break;
    case 'K':
      s1.peek();
      break;
    case 'F':
      s1.flush();
      break;
    default :
      cout << "\n Invalid Input";
    }

    cout <<"\n Enter operation or E to exit:";
    cin>>ch;
  }
  return 0;
}


