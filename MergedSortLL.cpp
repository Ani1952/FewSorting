#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    int data;
    Node *next = NULL;
};

void push(Node **head, int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = (*head);
    (*head) = new_node;
}

Node *merge(Node *a, Node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    Node *c;
    if (a->data < b->data)
    {
        c = a;
        c->next = merge(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge(a, b->next);
    }

    return c;
}

Node *midPoint(Node *head)
{
    Node *s = head;
    Node *f = head->next;
    while (f != NULL && f->next != NULL)
    {
        f = f->next->next;
        s = s->next;
    }
    return s;
}

Node *MS(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *mid = midPoint(head);

    Node *a = head;
    Node *b = mid->next;
    mid->next = NULL;

    a = MS(a);
    b = MS(b);

    return merge(a, b);
}

void SetData(Node **head, int n)
{
    cout << "Enter the Elements of the list" << endl;
    int new_data;
    for (int i = 0; i < n; i++)
    {
        cin >> new_data;
        Node *new_node = new Node();
        new_node->data = new_data;
        new_node->next = (*head);
        (*head) = new_node;
    }
}

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<"-->";
        head=head->next;
    }
    cout<<endl;
}
int main()
{
    Node *head=NULL;
    int n;
    cout<<"Enter The Size Of the 1st Linked List  :"<<endl;
    cin>>n;
    SetData(&head,n);
    print(head);
    MS(head);
    print(head);

    return 0;
}