#include <iostream>
using namespace std;

struct node{
	int data;
	node*next;
	node *prev;
	
};

class linkedList{
	private:
	
	node *head;
	node *tail;
public:
linkedList()
{
	head=NULL;
	tail=NULL;
}
void create(int num)
{
	node *temp= new node;
	temp->data=num;
	temp->next=NULL;
	    if (head == NULL)
{
    temp->prev = NULL;
    head = temp;

    }
else

    {
   tail->next=temp;
   temp->prev = tail;

    }
tail=temp;
}
 void display()
{
node *temp=new node;
	
temp=head;
while(temp)
	{
	cout<<temp->data<<"<->";
	temp=temp->next;
	
	}
cout<<"NULL";	
}
};

int main() 
{
	linkedList l;
	l.create(1);
	l.create(2);
	l.create(3);
	l.display();
	return 0;
}
