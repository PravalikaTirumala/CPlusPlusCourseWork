#include<iostream>
using namespace std;
class STACK
{
private:
int *s;
int N;

public:
STACK(int maxN){
s = new int[maxN];
N = 0;
}
int empty() const{
	if(N!= 0)
	cout<<"not empty"<<endl;
	else
	{
	cout<<"empty"<<endl;
	return N == 0;
	}
}
void push(int item){
s[N++] = item; 
}
int peek(){
cout<<s[--N];
return s[++N];
}
int pop(){
	if(N==0){
		cout<<"nothing to pop off; stack is empty"<<endl;
	}
	else
cout<<s[-- N];
return  0;
}
void flush(){
while(N!=0){
cout<<s[--N]<<" ";
}
}
};
int main()  {
  	STACK s1(100);
  	int a[10];
  	int x;
	  char ch;
  cout <<"Enter operation or Z to exit:";
  cin>>ch;

  while (ch!='Z')
  {
    switch (ch)
    {
    case 'P' : 
      cin >> x;
      s1.push(x);
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

    cout <<"\n Enter operation or Z to exit:";
    cin>>ch;
  }
  return 0;
}


