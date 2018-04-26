//dll
#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
	node *prev;
};

class llist
{
	private:
	node *head,*tail;
	
	public:
	llist()
	{
		head=NULL;
		tail=NULL;
	}
	
	void insert (int value)
	{
		node *temp=new node;
		temp->data=value;
		temp->next=NULL;
		if(head==NULL)
		{
			head=temp;
			temp->prev=NULL;
		}
		else
		{
			tail->next=temp;
			temp->prev=tail;
		}
		tail=temp;
	}
	void insertat(int pos,int value)
	{
	node *cur=new node;
	node *left= new node;
	node *temp=new node;
	temp->data=value;
	cur=head;
	if(pos>count())
	cout<<"\nInvalid index";
	else 
	{
	while(pos>1)
	{
		left=cur;
		cur=cur->next;
		pos--;
	}
	left->next=temp;
	temp->prev=left;
	temp->next=cur;
	cur->prev=temp;
	}
	}
	void deleteend()
	{
		node *temp=new node;
		temp=head;
		node *prev=new node;
		while(temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
		tail=prev;
		prev->next=NULL;
		delete temp;
	}
	void deleteat(int pos)
	{
		node *temp=new node;
		node *prev=new node;
		
		temp=head;
		if(pos>count())
		cout<<"\n Invalid";
		else
		{
		while(pos>1)
		{
			prev=temp;
			temp=temp->next;
			pos--;
		}
		prev->next=temp->next;
		temp->next->prev=prev;
		delete temp;
		}
	}
	int count()
	{
		node *temp=new node;
		temp=head;
		int c=0;
		while(temp!=NULL)
		{
			temp=temp->next;
			c++;
		}
		return c;
	}
	
	void display()
	{
		node *temp=new node;
		temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<"NULL\n";
		}
};
int main(){
	int count=0;
	llist l;
	l.insert(1);
	l.insert(2);
	l.insert(3);
	l.display();
	
	l.insertat(2,4);
	l.display();
	l.insertat(5,6);
	l.display();
	l.deleteend();
	l.display();
	l.deleteat(2);
	l.display();
	cout<<"\nThe number of element is:"<<l.count();
	return 0;
}
