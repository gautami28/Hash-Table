#include<iostream>
#include<conio.h>
#include <bits/stdc++.h>
#define size 10
#define F 0
#define T 1


using namespace std;

class hashtable
{
	public:
	int a[size],temp[size],chain[size];
	int x,i=0,j,head,h;
	int hash(int b)
	{
		return(b%size);
	}
	
	int insert()
	{
		cout<<"enter number to be inserted"<<endl;
		cin>>x;
		
		head = hash(x);
			
		while(temp[head]==T && i<size)
		{
			i++;
			head = (head + 1)%size;
		}
		
		if(i==size)
		{
			cout<<"table is full"<<endl;
			return 0;
		}
		
		while(chain[head]!=-1)
		{
			head = chain[head];
		}
		j = head;
		while(temp[j] && i<size)
		{
			j = (j+1)%size;
			i++;
		}
		
		if(i==size)
		{
			cout<<"table is full"<<endl;
			return 0;
		}
		
		a[j] = x;
		temp[j] = T;
		if(j!=head)
		{
			chain[head] = j;
		}
		
		
	}
		


	
	void display()
	{
		for(i=0;i<size;i++)
		{
			if(temp[i])
			{
				cout<<endl<<a[i]<<" "<<chain[i];
			}
			else
			{
				cout<<endl<<" "<<chain[i];
			}
		}
	}
	
	
};

int main()
{
	hashtable h1;
	int ch;
	cout<<endl<<"1.INSERT"<<endl<<"2.DISPLAY"<<endl;
	for(int i=0;i<size;i++)
		{
			h1.temp[i] = F;
			h1.chain[i] = -1;
		}
	while(ch!=3)
	{
	cout<<"Enter your choice:";
	cin>>ch;
	switch(ch)
		{
			case 1:	h1.insert();
					break;
				
			case 2:	h1.display();
					break;
					
			case 3: break;
	}
}
}
