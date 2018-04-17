

//First_inder Files
#include<iostream>
using namespace std;

//Declaring the structure of the node
struct node
{
  int data;
  int next;
  //Initializing all the elements and next values to -1 through constructor
  node()
  {
    data = -1;
    next = -1;
  }
};

//Function prototypes
void insert(int);
void insertAfter(int,int);
void display();
int lastIndex();
void deleteData(int);
void multiplyByTwo();
void reverse();

//Global declaration
int last_ind;
int first_ind =- 1;
int x,y;
char ch;
node A[100];

//Main function
int main()
{
  cout <<"Enter operation or E to exit:";
  cin>>ch;

  //Reading the operation from the user
  while (ch!='E')
  {
    switch (ch)
    {
    case 'A' : 
      cin >> x;
      insert(x);
      break;
    case 'I' :
      cin >> x >> y;
      insertAfter(x,y);
      break; 
    case 'T':
      display();
      break;
    case 'D':
      cin >> x;
      deleteData(x);
      break;
    case 'P':
      multiplyByTwo();
      break;
    case 'R':
      reverse();
      break;
    default :
      cout << "\n Invalid Input";
    }

    cout <<"\n Enter operation or E to exit:";
    cin>>ch;
  }
  return 0;
}

//Insert function
  void insert(int value)
  {
    last_ind = lastIndex();
    if(last_ind == 0)
      first_ind = last_ind+1;
    else
       A[last_ind].next = last_ind+1;
    A[last_ind+1].data = value;
    A[last_ind+1].next = 0;
  }

  void display ()
  {
    if(first_ind == -1)
      cout<<"\n No elemnts present";
    else
    {
      int i =1;
      while (i!=0)
      {
        cout<<A[i].data<< " ";
        i = A[i].next;
      }
    }
  }

  //Insert After function
  void insertAfter(int m,int n)
  {
    int hold;
    int temp = 1;
    //Advacing temp unless m is found
    while (A[temp].data != m)
      temp++;
    last_ind = lastIndex();
    hold=last_ind;
    //Inserting n at the end
    if(last_ind == temp)
      insert(n);
    //Inserting between two elements
    else
    {
      // Moving the elements after m one step below
      while(last_ind != temp)
      {
        // Moving the last element and making it's next value as 0 to indicate the end of the list
        if(hold == last_ind)
        {
          A[last_ind+1].data = A[last_ind].data;
          A[last_ind+1].next = A[last_ind].next;
        }
        //Moving the elements between m and the last element one step below
        else
        {
          A[last_ind+1].data = A[last_ind].data;
          A[last_ind+1].next = (A[last_ind].next)+1;
        }
        last_ind--;
      }
      //Inserting elemet n after m
      A[temp+1].data = n;
      A[temp+1].next = (A[temp].next)+1;
     }
  }

  //Function to find the index of last element present
  int lastIndex()
  {
    //Returns 0 if there is no element present
      if(first_ind == -1)
        return 0;
    //Returns the index of the last element
      else
      {
        last_ind = 1;
        while (A[last_ind].next != 0)
          last_ind++;
        return last_ind;
      }
  }

  //Delete function
  void deleteData(int d)
  {
    int temp = 1;
    while (A[temp].data != d)
      temp++;
    last_ind = lastIndex();
    if(first_ind == -1)
      cout<<"\n No elements to delete";
    else
    {
      //Deleting the last element 
      if(temp == last_ind)
      {
            A[temp].data = -1;
            if (temp != first_ind)
              A[temp-1].next = 0;
      //Deleting the only last element
            else
            {
              A[temp].next = -1;
              first_ind = -1;
            }
      }
      //Deleting the rest of elements
      else
      {
        while (A[temp].next != 0)
        {
          if(temp == (last_ind-1))
          {
            A[temp].data = A[temp+1].data;
            A[temp].next = 0;
          }
          else
          {
            A[temp].data = A[temp+1].data;
            A[temp].next = (A[temp+1].next)-1;
          }
          temp++;
        };
      }
      }
  }

  //Multiply By Two function
  void multiplyByTwo()
  {
    if(first_ind == -1)
      cout<<"\n No elements present";
    else
    {
      int temp = 1;
      while (A[temp].next != -1)
      {
        A[temp].data = ((A[temp].data)*2);
        temp++;
      };
    }
  }

  //Reverse function
  void reverse()
  {
    if (first_ind == -1)
      cout<<"\n Invalid operation";
    else
    {
      int temp = 1; 
      int z;
      last_ind = lastIndex();
      int hold = last_ind;
      while(temp <= (hold/2))
      {
        z = A[temp].data;
        A[temp].data = A[last_ind].data;
        A[last_ind].data = z;
        temp++;
        last_ind--;
      };
    }
  }

