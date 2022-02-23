#include<iostream>
#include<conio.h>
#include<iomanip>
#include<string.h>
#define size 5

using namespace std;

struct Node{
    int n;
    Node* link;
};


class List{
    private:
        Node* next;
        int len;

    public:
        Node* Head;
        Node *temp;

    List(){
        next = new Node;
        next->link = NULL;
        temp = next;
        Head = next;
        len = 0;
    }

    void insert(int num){
        next = new Node;
        next->link = NULL;
        temp->n = num;
        temp->link = next;
        temp = next;
        len+=1;
    }

    void print_in_detail(){
        Node* l;
        l = Head;
        for (int i = 0; i < len; i++){
            cout<<"No: "<<l->n<<" --> ";
            l = l->link;
        }
    }

    void print(){
        Node* l;
        l = Head;
        for (int i = 0; i < len; i++){
            cout<<l->n<<" ";
            l = l->link;
        }
    }

    int find(int num){
        Node* l;
        l = Head;
        for (int i = 0; i < len; i++){
            if (l->n == num){
                return i;
            }
            l = l->link;
        }
        return -1;
    }

    friend int length(List &li);
};


int length(List &li){
    return li.len;
}



class hashtable
{
	public:
		List arr[100];
		int hash_func(int x)
		{
			return(x%size);
		}
		
		int digit_extraction(int x)
		{
			return(x%100);
		}
		
		void add(int x)
		{
			int hash_value = hash_func(x);
			arr[hash_value].insert(x);
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
		h.add(a);
	}
	h.display();
	return 0;
}