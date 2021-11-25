#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    int data;
    Node *next = NULL;
};

void SetData(Node **head_ref, int n)
{
    cout << "Enter Node data" << endl;
    int new_data;
    for (int i = 0; i < n; i++)
    {
        cin >> new_data;
        Node *new_node = new Node();
        new_node->data = new_data;
        new_node->next = (*head_ref);
        (*head_ref) = new_node;
    }
}

void push(Node **head, int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = (*head);
    (*head) = new_node;
}

Node* merge(Node *a, Node* b){
	//Complete this method
	//base case
	if(a==NULL){
		return b;
	}
	if(b==NULL){
		return a;
	}

	//rec case
	Node * c;

	if(a->data < b->data){
		c = a;
		c->next = merge(a->next,b);
	}
	else{
		c = b;
		c->next = merge(a,b->next);
	}
	return c;
}


Node* mergeSort(Node * head){

	if(head==NULL ){
		return head;
	}

	Node * slow = head;
	Node * fast = head->next;

	while(fast!=NULL and fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	Node *mid=slow;

	Node * a = head;
	Node * b = mid->next;
	mid->next = NULL;

	a = mergeSort(a);
	b = mergeSort(b);

	return merge(a,b);

}

void print(Node *head)
{

    while (head != NULL)
    {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    int size;
    Node *head = NULL;
    cout << "Enter the length of linked list" << endl;
    cin >> size;
    SetData(&head, size);
    print(head);
    mergeSort(head);
    print(head);

    return 0;
}