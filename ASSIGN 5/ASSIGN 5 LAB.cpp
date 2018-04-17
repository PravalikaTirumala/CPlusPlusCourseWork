#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	
	int tot_ver,source=0,dest=0,i,vertices,j,row,col,k;
	int B[tot_ver];
	row=tot_ver;
	col=tot_ver;
	int adj_matric[20][20]={0};	
cout<<"enter number of vertices for the graph"<<endl;
	cin>>tot_ver;
cout<<"enter the vertices"<<endl;
while(i!=-1 || j!=-1)
{ 	
cin>>i>>j;
adj_matric[i][j]=1;
}	
cout<<"Graph G created is"<<endl;
		
	for (i=1; i <= tot_ver; i++)
	{
		for (j=1; j <= tot_ver; j++)
		{
		    cout<<adj_matric[i][j]<<" ";
		}
		cout<<endl;
	}
	while(source!= -1 && dest != -1)
	{
	cout<<"enter source and destination"<<"  "<<endl;
	cin>>source>>dest;
	cout<<endl;
		
	for(i=1;i<=tot_ver;i++)
	{
		if(i==source)
		B[i]=0;
			else
			{
			if(adj_matric[source][i]==1)
			B[i]=1;	
			else
			B[i]= -1;
			}
	}
	/*for(i=1;i<=tot_ver;i++)
	{
	cout<<B[i]<<"  ";
	}*/
		if(source==dest)
	{
		cout<<"yes - destination can be reached"<<endl;
	}
	else if(B[dest]==1)
	{
		cout<<"yes  -  reached in 1 step "<<endl;
	}
	else
	{
	for(i=1;i<=tot_ver;i++)
	{
		for(j=1;j<=tot_ver;j++)
		{
			if(B[j]==i)
			{
			for(k=1;k<=tot_ver;k++)
				{
				if(adj_matric[j][k]==1  &&  B[k] != 1)
				B[k]=i+1;		
				}	
			}
		}
		if(B[dest]!= -1)
				{
					cout<<"yes - destination can be reached IN  "<<i+1<<" steps"<<endl;
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


