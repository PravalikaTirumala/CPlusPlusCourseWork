
#include <iostream>
#include <cstdlib>
using namespace std;

class STACK 
  {
    private:
      int *s; int N;
	public:
 	
      STACK(int maxN)
        { 
		s = new int[maxN]; 
		N = 0; 
		cout<<"\n Stack of the given size created\n"; }

      int empty()//check for empty
        { 
		return N == 0;
		}

      void push(int item)//insert items in to stack
        { 
		  s[N++] = item; 
		}
       int peek() //output top integer
       {
       	if(empty())
	        {
	        	cout<<"Nothing to show\n";
	        	 return 0;
			}
			else
			{
	      		int c=N;
				return s[--c];
				cout<<"\n not empty\n";
		    }
	   }

      int pop()//pops the elements
        { 
	        if(empty())
	        {
	        	cout<<"Nothing to pop off\n";
	        	 return 0;
			}
			else
			{
				cout<<s[--N];
				cout<<endl;
			  
			}
         
		}

      void flush()//print in lifo
      {
      	if(empty())
        {
        	cout<<"Nothing to FLUSH \n";
     	}
		else
		{
      	while(N!=0)
      	{
      		cout<<s[--N]<<" ";
      				
		}
		//cout<<" Stack has been reset ";
      } 
  }
  };

  int main()
  {
  	int item,x=100;
  	char input_value;
   	STACK save(x);
  	cout<<"\n Press P to push integer x onto the stack\n";
	cout<<"Press R to pop off the stack top and display\n";
	cout<<"Press E to check wjeather stack is empty or not\n";
	cout<<"Press K to output the stack top integer x using function peek\n";
	cout<<"Press F to output the entire content of the stack in last-in first-out order; empties the stack\n";
	cout<<"Press Q to quit the program\n";
 	cin>>input_value; 

  while(input_value!='Q'||input_value!='q')
  {
  	if(input_value=='P'||input_value=='p')
  	{
  		cout<<" Enter the value ";
  		cin>>item;
  		save.push(item);
	}

	else if(input_value=='R'||input_value=='r')
	{
		
		save.pop();
	}
	
	else if(input_value=='E'||input_value=='e')
	{
		
		if(save.empty())
		{
			cout<<" the stack is empty\n";
		}
		else
		{
			cout<<"the stack is not empty\n";
		}
	}

	else if(input_value=='K'||input_value=='k')
	{
		cout<<" the element on top of the stack is - \t";
		if(save.empty())
		{
			cout<<" stack is empty nothing to peek\n";
		}
		else
		{
			cout<<save.peek();
		}
	}
	
	else if(input_value=='F'||input_value=='f')
	{
		cout<<" Now flushing the complete stack \n";
		save.flush();
	}

	else if(input_value=='Q'||input_value=='q')
	{
		break;		
	} 

 	cin>>input_value;
  }

  	cout<<" Exiting now...\n";

	return 0;
  	system("pause");
  }


