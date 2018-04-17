/*C <int r> : Create the root node with item r. If the tree is not empty (i.e. the root exists), return an error
L <intp><int l>:  Find the node with item p.Let u be that node. Create a new node v with item l. 
Make node v node u's left child. If node u has already a left child, return an error
R <int p><int r>:  Find the node with item p. Let u be that node. Create a new node v with item r. Make node v node u's right child.
 If node u has already a right child, return an error
P: Print the items in nodes in a level order traversal manner
S <int p>: Find the node with item p. Let u be that node.Print the items in nodes in the subtree rooted at u in level order traversal manner*/

#include<iostream>
using namespace std;
struct node 
	{ 
	int item;
	int level;
	node *left, *right; 
	node(int x)
	{
	item = x; left = NULL; right = NULL;
	}
	node(int x,int l)
	{
	item = x; left = NULL; right = NULL;
	level=l;
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
	void put(link l)
		{
		q[tail++]=l;
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
		root=new node(r_val,1);
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
		temp=find_req_node(root,pl);
			if (temp->left==NULL)
			{
				int tl=temp->level+1;
			temp->left=new node(l_val,tl);
			cout<<"node with value"<<l_val<<"is added to the left side"<<endl;
			}
			else
			cout<<"left child already present"<<endl;
	return 0;
	}
//to insert right child
	int create_right(int pr,int r_val)
	{
		temp=find_req_node(root,pr);
			if (temp->right==NULL)
			{
				int tr=temp->level+1;
			temp->right=new node(r_val,tr);
			cout<<"node with value"<<r_val<<"is added to the right side"<<endl;
			}
			else
			cout<<"right child already present"<<endl;
	return 0;
	}
	void print_tree_height()
	{
		int hl=0,hr=0;
		if(root==NULL)
		cout<<"there is no tree"<<endl;
		else if (root->left ==0 && root ->right ==0)
			{
			cout<<"height of the treee is"<<" "<< root->level;
			cout<<endl;
			}
		else
		{
		QUEUE q(30);
		h=NULL;
		q.put(root);
			while (!q.empty())
			{
				h = q.get(); 
				if (h->left != 0)
				{ 
				q.put(h->left);
				hl=h->left->level;
				}
        	if (h->right != 0)
        	{
			 q.put(h->right);
			 hr=h->right->level;
			}
 			}
			 if(hl>=hr)
			 cout<<"height of the tree is"<<" "<<hl<<endl;
			 else
			cout<<"height of the tree is"<<" "<<hr<<endl;
		}
	}
	
  int main()
  {
  	 	link temp=NULL;
  	 	int r_val,l_val,pl,pr,plevel;
  	 	link root =NULL;
  	char ch;
	cout<<"enter an operation to perform"<<endl;
  	cout<<"C- to create root node---"<<endl;
  	cout<<"L- to add left node---"<<endl;
  	cout<<"R- to add right node---"<<endl;
  	cout<<"P-Print whole tree in level order---"<<endl;
  	cout<<"E- to exit---"<<endl;
  	cin>>ch;
  	while(ch != 'E')
  	{
  	switch(ch)
  	{
	  case 'C':
	  	{
	  	cout<<"enter value to make it as root node"<<endl;
	  	cin>>r_val;
	  	create_root(r_val);
	  	break; 
		}
	  case 'L':
	  	{
		  cout<<"enter node value and value to make it as left child"<<endl;
	  	cin>>pl>>l_val;
	  	create_left(pl,l_val);
	  	break;
	  	}
	  case 'R':
	  	{
		  cout<<"enter node value and value to make it as right child"<<endl;
	  	cin>>pr>>r_val;
	  	create_right(pr,r_val);
	  	break;
	  }
	  case 'P':
	  	print_tree_height();
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

