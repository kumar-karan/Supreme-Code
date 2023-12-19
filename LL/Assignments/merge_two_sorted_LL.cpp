#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }
};

int getLength(Node* head)
{
    int len = 0;
    Node* temp = head;
    while (temp != NULL)
    {
        temp = temp-> next;
        len ++;
    }
    return len;
}

void print(Node* &head)
{
    Node* temp = head;
    while(temp!= NULL)
    {
        cout << temp -> data << " ";
        temp = temp-> next;
    }
    cout << endl;
}

Node* merge_two_sorted_LL(Node* head1, Node* head2)
{
    Node* sortedHead = NULL;
    Node* sortedTail = NULL;
    while(head1 != NULL && head2 != NULL)
    {
        if(head1 -> data <= head2 -> data)
        {
            Node* newNode = new Node(head1 -> data);
            if(sortedHead == NULL)
            {
                sortedHead = newNode;
                sortedTail = newNode;
            }
            else
            {
                sortedTail -> next = newNode;
                sortedTail = newNode;
            }  
            head1 = head1 -> next;
        }
        else
        {
            Node* newNode = new Node( head2 -> data);
            if(sortedHead == NULL)
            {
                sortedHead = newNode;
                sortedTail = newNode;
            }
            else
            {
                sortedTail -> next = newNode;
                sortedTail = newNode;
            }  
            head2 = head2 -> next;
        }
    }
    while(head1 != NULL)
    {
        Node* newNode = new Node( head1 -> data);
        sortedTail -> next = newNode;
        sortedTail = newNode; 
        head1 = head1 -> next;
    }
    while(head2 != NULL)
    {
        Node* newNode = new Node( head2 -> data);
        sortedTail -> next = newNode;
        sortedTail = newNode; 
        head2 = head2 -> next;
    }
    return sortedHead;
    
}

int main()
{
    Node* head1 = new Node(10);
    Node* second1 = new Node(20);
    Node* third1 = new Node (30000);
    head1 -> next = second1;
    second1-> next = third1;

    Node* head2 = new Node (15);
    Node* second2 = new Node (100);
    Node* third2 = new Node (150);
    head2->next =second2;
    second2-> next = third2;

    print(head2);
    print(head1);

    Node* sort = merge_two_sorted_LL(head1, head2);
    print(sort);
    return 0;
}