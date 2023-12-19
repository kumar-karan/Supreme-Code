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

void kthNodeFromEnd( Node* &head, int k)
{
    Node* temp = head;
    int len = getLength(head);
    k = len- k -1;
    if( head == NULL || head -> next == NULL || k == 0)
        cout <<  head -> data;
    while(k --)
    {
        temp = temp -> next;
    }
    cout << temp -> data << endl;

}

void kthNodeFromEndRecursion (Node* head, int &k, int &ans)
{
    if(head == NULL)
        return;
    kthNodeFromEndRecursion(head -> next, k, ans);

    if(k == 0)
    {
        ans = head -> data;
    }
    k--;
}

int main()
{
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(30);
    Node* sixth = new Node(20);
    Node* seventh = new Node(10);

    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = fifth;
    fifth -> next = sixth;
    sixth -> next = seventh;

    print(head);

    int k =4;

    kthNodeFromEnd(head ,k);
    int ans = -1;
    kthNodeFromEndRecursion(head , k,ans);
    cout << ans;

    return 0;
}