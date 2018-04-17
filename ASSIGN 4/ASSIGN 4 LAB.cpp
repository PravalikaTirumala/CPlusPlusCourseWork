#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;


struct node
{
   int index;
   int data;
   node* next;
};
typedef node* link;//The purpose of typedef is to assign alternative names to existing types,
int A[100];


link createList()
{
    node* head = NULL;

   for(int i = 0; i < 100; i++)
       A[i] = NULL;

    return head;
}


void insert(link *head, int i, int value)
{
  
   // insert in to the array
   A[i] = value;

   // insert in the linked list
   link newNode = (link)malloc(sizeof(node));
   newNode->index = i;
   newNode->data = value;
//NEW node temp2 with null
   link temp2 = NULL;
   link temp1 = *head; 
   //to search for the required index to insert the value
   while(temp1 != NULL && temp1->index < i)
   {
       temp2 = temp1;
       temp1 = temp1->next;
   }

   if(temp1 != NULL && temp1->index == i)
   {
       temp1->data = value;
   }
   else if(temp2 == NULL) // insert at first
   {      
       newNode->next = *head;
       *head = newNode;
   }
   else if(temp1 == NULL) // insert at last
   {
       temp2->next = newNode;
       newNode->next = NULL;//assign NULL to the new node as it is appended to tha last
   }
   else // insert in the middle of the list
   {
       temp2->next = newNode;
       newNode->next = temp1;
   }
}

void increment(link *head)
{
	if(head == NULL)
       cout << "No data in A now" << endl;
   else
   {
       link temp1 = *head;
       while(temp1 != NULL)
       {
           temp1->data=temp1->data+1;
            cout << "index: " << temp1->index << " value: " << temp1->data << endl;
		   //temp1->data++;//cout << "index: " << temp1->index << " value: " << A[temp1->index] << endl;
           temp1 = temp1->next;
       }
   }
 
}
void remove(link *head, int i)
{
   
	if(head == NULL)
   {
       cout << "The list is empty!" << endl;
       return;
   }

   link temp2 = NULL;
   link temp1 = *head;
   while(temp1 != NULL && temp1->index != i)
   {
       temp2 = temp1;
       temp1 = temp1->next;
   }

   if(temp1 == NULL)
   {
       cout << "No data at the index " << i << "." << endl;
       return;
   }

   if(temp2 == NULL) // found at first
       *head = (*head)->next;
   else if(temp1->next == NULL) // found at last
       temp2->next = NULL;
   else // found at other location
       temp2->next = temp1->next;
  
   A[i] = NULL;
}

void printArray(link head)
{
   if(head == NULL)
       cout << "No data in A now" << endl;
   else
   {
       link temp1 = head;
       while(temp1 != NULL)
       {
           cout << "index: " << temp1->index << " value: " << A[temp1->index] << endl;
           temp1 = temp1->next;
       }
   }
}

void resetArray(link *head)
{
   *head = createList();

   for(int i = 0; i < 100; i++)
       A[i] = NULL;
  
   cout << "A has been reset" << endl;
}


int main()
{
   // build an empty list
   link L = createList();      //typedef allows you to declare instances of a struct without using keyword "struct"
   char ch;
  
   cout << "---A T R AND I represents----------------" << endl;
   cout << "A i x : Set A[i]=x" << endl;
   cout << "T: Output all data values in A" << endl;
   cout << "R: ResetS A" << endl;
   cout << "I: increment data" << endl;
   cout << "Other than A/T/R- exit." << endl;
   cout << "Sample input/output:" << endl << endl;
   cin >> ch;

   while(ch == 'A' || ch == 'T' || ch == 'R' ||ch=='I')
   {
       if(ch == 'A')
       {
           int i, value;

           cin >> i >> value;

           insert(&L, i, value);                      
       }
       
       else if(ch=='I')
       		{
       		increment(&L);
       		}
       else if(ch == 'T')
           printArray(L);
       else
           resetArray(&L);

       cout << endl;
       cin >> ch;
   }
  
   cout << endl;
   system("pause");
   return 0;
}

