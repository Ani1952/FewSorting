
#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

void SetData(Node **head_ref,int n){
	cout<<"Enter Node data"<<endl;
	int new_data;
	for(int i=0;i<n;i++){
		cin>>new_data;
		Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
	}
}

void reverseList(Node **head){
	Node *prev,*curr,*next;
	prev=next=NULL;
	
	curr=*head;
	 while(curr!=NULL){
	 	next=curr->next;// saving the next node address
	 	curr->next=prev;// breaking and flipping node pointer LINK
	 	prev=curr;curr=next;// ready for next wave
	 }
	 *head=prev;
}

void reverse(Node ** head){
	Node * p,*n,*c;
	p=n=NULL;
	
	c=*head;
	while(c!=NULL){
		n=c->next;
		c->next=p;
		p=c;c=n;
	}
	*head=p;
}
void printList(Node *node)
{
    while (node != NULL)
    {
        cout<<" "<<node->data;
        node = node->next;
    }
}

int main(){

int size;Node *head=NULL;
cout<<"Enter the length of linked list"<<endl;
cin>> size;
SetData(&head,size);
printList(head);
reverseList(&head);
cout<<"reversing"<<endl;
printList(head);
return 0;
}

