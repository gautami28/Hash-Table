#include<iostream>
#include<conio.h>
#include<iomanip>
#include<string.h>
#define size 5

using namespace std;

struct Node{
    string name;
    int prn_num;
    Node* link;
};


class linkedList{
    private:
        Node* nextnode;
        int len;

    public:
        Node* Head;
        Node *temp;

    linkedList(){
        nextnode = new Node;
        nextnode->link = NULL;
        temp = nextnode;
        Head = nextnode;
        len = 0;
    }

    void append(int num, string Name){
        nextnode = new Node;
        nextnode->link = NULL;
        temp->prn_num = num;
        temp->name = Name;
        temp->link = nextnode;
        temp = nextnode;
        len+=1;
    }

    void print_in_detail(){
        Node* l;
        l = Head;
        for (int i = 0; i < len; i++){
            cout<<"Name: "<<l->name<<", "<<"Phone No: "<<l->prn_num<<" --> ";
            l = l->link;
        }
    }

    void print(){
        Node* l;
        l = Head;
        for (int i = 0; i < len; i++){
            cout<<l->prn_num<<" ";
            l = l->link;
        }
    }

    int find(int num){
        Node* l;
        l = Head;
        for (int i = 0; i < len; i++){
            if (l->prn_num == num){
                return i;
            }
            l = l->link;
        }
        return -1;
    }

    friend int length(linkedList &lst);
};


int length(linkedList &lst){
    return lst.len;
}



class hashtable
{
	public:
		linkedList arr[100];
		int hash_func(int x)
		{
			return(x%size);
		}
		
		void add(int x,string name)
		{
			int hash_value = hash_func(x);
			arr[hash_value].append(x,name);
		}
		
		void display()
		{
			for(int i=0;i<size;i++)
			{
				arr[i].print_in_detail();
				cout<<"\n-----------\n";
			}
		}
		
};

int main()
{
	hashtable h;

	for(int i=0;i<size;i++)
	{
		int a;
		string name;
		cout<<"enter numbers: "<<endl;
		cin>>a;
		cout<<"name: "<<endl;
		cin>>name;
		h.add(a,name);
	}
	h.display();
	return 0;
}