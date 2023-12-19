/* 
! Tortioise Algorithm 
* ek slow ek fast 
* fast do jump karega slow ek jump karega 
* slow tabhi jump karega jab fast do jump kar chuka ho
* fast NULL pe aajayega to slow ko mat jump karao 

*1. slow = head ; fast = head;
*2. fast ko do step ; slow ko 1 step 
*3. Return slow; 

*/

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
        this -> data = data ;
        this -> next = NULL;
    }

};

void print(Node* &head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp-> data << " ";
        temp = temp -> next;
    }
    cout << endl; 
}

Node* getMiddle(Node* &head)
{
    Node* slow = head;
    Node* fast = head;

    if(head == NULL)
    {
        cout << " Linked List is empty"<< endl;
        return head;
    }
    if(head-> next == NULL)
    {
        return head;
    }
    while(slow != NULL && fast != NULL)
    {
        fast =  fast -> next; 
        if(fast != NULL)
        {
            fast = fast -> next;
            slow = slow -> next;
        }
    }
    return slow;
}

int main()
{
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);

    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = fifth; 
    fifth -> next = sixth;
    sixth -> next = NULL;


    print(head);

    cout << "Middle node is : "<< getMiddle(head) -> data << endl;   


    
    return 0;
}
