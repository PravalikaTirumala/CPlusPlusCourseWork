/*C <int r> : Create the root node with item r. If the tree is not empty (i.e. the root exists), return an error
L <intp><int l>:  Find the node with item p.Let u be that node. Create a new node v with item l. 
Make node v node u's left child. If node u has already a left child, return an error
R <int p><int r>:  Find the node with item p. Let u be that node. Create a new node v with item r. Make node v node u's right child.
 If node u has already a right child, return an error
P: Print the items in nodes in a level order traversal manner
S <int p>: Find the node with item p. Let u be that node.Print the items in nodes in the subtree rooted at u in level order traversal manner
N : count the number of nodes
D : deletes the node 
O :print only odd values in the tree
K : print left branches only*/ 

#include<iostream>
using namespace std;

struct node 
	{ 
	int item;
	node *left, *right; 
	node(int x)
	{
	item = x; left = NULL; right = NULL;
	}
	};
typedef node* link;
link root;
link temp;
link h;
class QUEUE 
  {
	private:
	link *q;
	int head, tail,N;
	public:
		QUEUE(int maxN)
        { 
		q = new link[maxN+1]; 
          N = maxN+1;
          head = N; 
          tail = 0; 
        }
	int empty() const
		{
		return head % N==tail;
		}
	void put(link item)
		{
		q[tail++]=item;
		tail=tail %N;
    	}
    link get()
	{
		head=head % N;
		return q[head++];
	}
};

	// creation of root node
	int create_root(int r_val)
	{
		if(root==NULL)
		{
		root=new node(r_val);
		cout<<"root is created"<<endl;
		}
		else
		cout<<"Tree is not empty"<<endl;
		return 0;
	}
	//to find the node with the given value
	link find_req_node(link root,int p)
	{
		if(root!=NULL)
		{
		QUEUE q(30);
		h=NULL;
		q.put(root);
			while (!q.empty())
			{
			h = q.get(); 
				if(h->item==p)
				return h;
				else
				{
					if (h->left != NULL)
					q.put(h->left);
					if (h->right != NULL)
					q.put(h->right);	
				}	
 			}	
		}
		return NULL;	
	}
	//to insert left child
	int create_left(int pl,int l_val)
	{
		if(root==NULL)
		{
		cout<<"There is no tree"<<endl;
		return NULL;
		}
		else{
		temp=find_req_node(root,pl);
			if (temp->left==NULL)
			{
			temp->left=new node(l_val);
			cout<<"node with value"<<l_val<<"is added to the left side"<<endl;
			}
			else
			cout<<"left child already present"<<endl;
	return 0;
	}
	}
//to insert right child
	int create_right(int pr,int r_val)
	{
		if(root==NULL)
		{
		cout<<"There is no tree"<<endl;
		return NULL;
		}
		else{
		temp=find_req_node(root,pr);
			if (temp->right==NULL)
			{
			temp->right=new node(r_val);
			cout<<"node with value"<<r_val<<"is added to the right side"<<endl;
			}
			else
			cout<<"right child already present"<<endl;
	return 0;
	}
	}
	void print_tree()
	{
		if(root==NULL)
		cout<<"tree is empty"<<endl;
		else
		{
		QUEUE q(30);
		h=NULL;
		q.put(root);
			while (!q.empty())
			{
			h = q.get(); 
			cout<<h->item<<" ";
				if (h->left != 0) q.put(h->left); 
        	if (h->right != 0) q.put(h->right); 
			}	
 		}	
	}	
	void print_level(int plevel)
	{
		temp=find_req_node(root,plevel);
		QUEUE q(30);
		h=NULL;
		q.put(temp);
			while (!q.empty())
			{
			h = q.get(); 
			cout<<h->item<<" ";
				if (h->left != 0) q.put(h->left); 
        	if (h->right != 0) q.put(h->right);
			//cout<<endl; 
			}	
	}
	void count_numnodes()
	{
	int count=0;
	h=NULL;
		QUEUE q(30);
	if(root==NULL)
	cout<<"there is no tree"<<endl;
	else if(root->left==NULL && root->right==NULL)
	{
	count++;
	cout<<"number of nodes are"<<count<<endl;
	}
	else
	{
		count=1;
	q.put(root);
	while(!q.empty())
	{
		h=q.get();
		if(h->left!=NULL)
			{
			q.put(h->left);
			count++;
			}	
		if(h->right!=NULL)
			{
			q.put(h->right);
			count++;
			}
	}
	cout<<"number of nodes are"<<count<<endl;
	}
}
void delete_node(int d)
{
if(root==NULL)
cout<<"there is no tree"<<endl;
else if(root->item==d)
{
	h=root;
	cout<<"root is the req node, hence complete tree needs to be deleted"<<endl;
	int i=h->item;
	delete h;
	root=NULL;
}
else
	{
	QUEUE q(30);
	h=NULL;
	q.put(root);
	while(! q.empty())
		{
		h=q.get();
		if(h->left != NULL) 
			{
				if(h->left->item==d)
				h->left=NULL;
				else
				q.put(h->left);
			}
		if(h->right != NULL) 
			{
			if(h->right->item==d)
			h->right=NULL;
			else
			q.put(h->right);			
			}		
		}
	}	
}
void print_tree_odd()
	{
		if(root==NULL)
		cout<<"tree is empty"<<endl;
		else
		{
		QUEUE q(30);
		h=NULL;
		q.put(root);
			while (!q.empty())
			{
			h = q.get(); 
			if(h->item%2==1)
			cout<<h->item<<" ";
				if (h->left != 0) q.put(h->left); 
        	if (h->right != 0) q.put(h->right); 
			}	
 		}	
	}
void print_left()
{
if(root==NULL)
		cout<<"tree is empty"<<endl;
		else
		{
		QUEUE q(30);
		h=NULL;
		q.put(root);
		cout<<root->item<<" ";
			while (!q.empty())
			{
			h = q.get(); 
				if (h->left != 0) 
				{
				cout<<h->left->item<<" ";
				q.put(h->left);
				}
        	if (h->right != 0) q.put(h->right); 
			}	
 		}	
}	
int main()
  {
  	 	link temp=NULL;
  	 	int r_val,l_val,pl,pr,plevel,del_v;
  	 	link root =NULL;
  	char ch;
	cout<<"enter an operation to perform"<<endl;
  	cout<<"C- to create root node---"<<endl;
  	cout<<"L- to add left node---"<<endl;
  	cout<<"R- to add right node---"<<endl;
  	cout<<"P-Print whole tree in level order---"<<endl;
  	//cout<<"S-print at given level---"<<endl;
  	cout<<"E- to exit---"<<endl;
  	cin>>ch;
  	while(ch != 'E')
  	{
  	switch(ch)
  	{
	  case 'C':
	  	cout<<"enter value to make it as root node"<<endl;
	  	cin>>r_val;
	  	create_root(r_val);
	  	break; 		 
	  case 'L':
	  	cout<<"enter node value and value to make it as left child"<<endl;
	  	cin>>pl>>l_val;
	  	create_left(pl,l_val);
	  	break;
	  case 'R':
	  	cout<<"enter node value and value to make it as right child"<<endl;
	  	cin>>pr>>r_val;
	  	create_right(pr,r_val);
	  	break;
	  case 'P':
	  	print_tree();
	  	break;
	  case 'S':
	  	cout<<"enter level"<<endl;
	  	cin>>plevel;
	  	print_level(plevel);
	  	break;
	  case 'N':
	  	count_numnodes();
	  	break;
	  case 'D':
	  	cout<<"enter the node value to delete"<<endl;
	  	cin>>del_v;
	  	delete_node(del_v);
	  case 'O':
	  	print_tree_odd();
	  	break;
	  case 'K':
	  	print_left();
	  	break;
	  case 'E':
	  	break;
	  default:
	  	cout<<"invalid input"<<endl;
	  }
	  cout<<"enter an operation to perform or E to exit"<<endl;
	  cin>>ch;
	  	
	}
  return 0;	
  }

