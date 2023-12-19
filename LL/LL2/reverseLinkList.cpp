#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node()
    {
        this-> data = 0;
        this-> next = NULL;
    }
    Node(int data)
    {
        this-> data = data;
        this-> next = NULL;
    }
};

void print(Node* head)
{
    Node* temp = head;
    while ( temp != NULL)
    {
        cout<< temp-> data << " ";
        temp = temp -> next;
    }
    cout << endl; 
}

Node* reverse(Node* &prev, Node* &curr)
{
    // base case 
    if(curr == NULL)
    {
        return prev;
    }

    //! Recursive Calls
    Node* forward = curr -> next;
    curr -> next = prev;

    return reverse(curr, forward);
}

Node* reverseLoop ( Node* &head)
{
    Node* prev = NULL;
    Node* curr = head;

    while(curr!= NULL)
    {
        Node* temp = curr -> next;
        curr-> next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

Node* reverseRecurrsion ( Node* &prev, Node* &curr)
{
    // Node* prev = NULL;
    // Node* curr = head;
    
    //! base case
    if(curr == NULL)
    {
        return prev;
    }

    Node* temp = curr -> next;
    curr-> next = prev;
    prev = curr;
    curr = temp;

    return reverseRecurrsion(prev, curr);

}



int main()
{
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    first-> next = second;
    second-> next = third;
    third-> next = fourth;
    fourth-> next = fifth;

    Node* head = first;

    print(head);

    Node* prev = NULL;
    Node* curr = head;



    // head = reverse(prev,curr);
    // print(head);
    
    // head = reverseRecurrsion(prev,curr);
    // print(head);

    head = reverseLoop(head);
    print(head);
    return 0;
}