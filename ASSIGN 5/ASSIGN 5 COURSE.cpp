#include <iostream>
using namespace std;	
	struct node 
  	{
  	int v;
  	node* next=NULL; 
  	node(int x, node* t) 
      {
	   v = x; 
	   next = t; 
	  } 
	  
  	};
typedef node *link;

int main()
  { 
  //declarations
  int source,dest,i,tot_ver, j,k;;
  int B[tot_ver];//array to store steps
  link head;
  
  //total number of vertices
  cout<<"enter number of vertices"<<endl;
  cin>>tot_ver;
  link adj[tot_ver];//arrray of pointers
    
	//initialisig array of pointers to null
	for (i = 1; i <= tot_ver; i++) 
	adj[i] = NULL;
	
	//creating adj list with neighbouring nodes in the list
	cout<<"enter vertices for the graph-2 at a time"<<endl;
    while (i!=-1 || j!=-1)
      { 
      	cin >> i >> j;
        //adj[j] = new node(i, adj[j]);
        adj[i] = new node(j, adj[i]);
      }
      
	  //to check reachability
	  
    	while(source != -1 || dest != -1)
    	{
    	cout<<"enter source and destination to check for reachability"<<endl;
    	cin>>source>>dest;
    	cout<<endl;
    	
		for(i=1;i<=tot_ver;i++)
 		{
 		if(i==source)
		B[i]=0;
		else
		B[i]=-1;
		}
		
		head=adj[source];//point head to where the source is pointing to
		while(head!=NULL)//traverse till the end and check for the destination
		{
		B[head->v]=1;
		head=head->next;
		}
		
	
	if(source==dest)
	{
		cout<<"yes - destination can be reached"<<endl; 
	}
	else if(B[dest]==1)
	{
		cout<<"reached in 1 step"<<endl;
	}
	else
	{
			link temp;
	for(i=1;i<=tot_ver;i++)
	{
		for(j=1;j<=tot_ver;j++)
		{
			if(B[j]==i)
			{
		
			
				temp=adj[j];
				while(temp!=NULL)
				{
					if(B[temp->v]!=1)
					{
					B[temp->v]=i+1;
					}
				temp=temp->next;
				}
				
		
			}
		}
		if(B[dest]!= -1)
				{
				cout<<"destination can be reached  "<<i+1<<"  steps"<<endl;
					break;
				}
	} 	
		
	}

	if(B[dest]== -1)
	{
	cout<<"No - Destination cant be reached"<<endl;
	}
	}
      return 0;
  }



