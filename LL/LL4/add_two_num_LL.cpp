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

void print(Node* &head)
{
    if ( head == NULL)
    {   cout<< "LL IS EMPTY "<<endl;
        return;
    }
        
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp-> data << " ";
        temp = temp -> next;
    }
    cout << endl; 
}

Node* reverseLoop ( Node* &head)
{
    Node* prev = NULL;
    Node* curr = head;

    Node* forward = curr -> next;

    while ( curr != NULL)
    {
        forward = curr -> next;
        curr -> next = prev ; 
        prev = curr;
        curr = forward;
    }
    return prev;
}

Node* solve(Node* &head1, Node* &head2)
{
    //*S1 Reverse Both LL 

    //*2. Add Both LL
    //* Reverse Ans waali LL 

    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1; 

    head1 = reverseLoop(head1);
    head2 = reverseLoop(head2);

    Node* ansHead = NULL;
    Node* ansTail = NULL;
    int carry = 0;

    while( head1 != NULL && head2 != NULL)
    {
        int sum = carry + head1-> data + head2 -> data;
        int digit = sum%10;
        carry = sum /10;

        Node* newNode = new Node(digit);

        if( ansHead == NULL)
        {
            ansHead = newNode;
            ansTail = newNode;
        }
        else
        {
            ansTail -> next = newNode;
            ansTail = newNode;
        }

        head1 = head1 -> next;
        head2 = head2 -> next;
    }

    while(head1 != NULL)
    {
        int sum = carry + head1-> data;
        int digit = sum%10;
        carry = sum /10;

        Node* newNode = new Node(digit);

        ansTail -> next = newNode;
        ansTail = newNode;
        head1 = head1 -> next;    
    }
    while(head2 != NULL)
    {
        int sum = carry + head2 -> data;
        int digit = sum%10;
        carry = sum /10;

        Node* newNode = new Node(digit);

        ansTail -> next = newNode;
        ansTail = newNode;
        head2 = head2 -> next;    
    }

    //! Handle Carry Alag se 

    while(carry != 0)
    {
        int sum = carry;
        int digit = sum%10;
        carry = sum /10;

        Node* newNode = new Node(digit);

        ansTail -> next = newNode;
        ansTail = newNode;
    }

    ansHead = reverseLoop(ansHead);
    return ansHead;
}

int main()
{

    Node* head1 = new Node(2);
    Node* second1 = new Node(4);
    head1 -> next = second1;

    Node* head2 = new Node (2);
    Node* second2 = new Node (3);
    Node* third2 = new Node (4);
    head2->next =second2;
    second2-> next = third2;

    print(head2);
    print(head1);
    Node* ans = solve(head1,head2);
    cout << endl;

    print(ans);
    return 0;
}