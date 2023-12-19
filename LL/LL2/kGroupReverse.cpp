// ! IMPORTANT 


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
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp-> data << " ";
        temp = temp -> next;
    }
    cout << endl; 
}
/* 
*1. Loop -> reverse k nodes
*2. head -> next = recursion ka ans
*3. return prev
*/

int getLength(Node* head)
{
    int len = 0;
    Node* temp = head;
    while ( temp != NULL)
    {
        temp = temp-> next;
        len ++;
    }
    return len;
}

Node* reverseKNodes (int k, Node* & head)
{

    /*
    *1. Reverse first K nodes
    *2. 
    */
    if(head == NULL)
    {
        cout << " Linked List is empty"<< endl;
        return NULL;
    }
    // if(head-> next == NULL)
    // {
    //     return head;
    // }

    int len = getLength(head);
    // * can ignore k> len 
    if(k > len)
    {
       // cout<<"Enter valid value for k "<< endl;
        return head;
    }

    //! STEP A: REVERSE first K nodes of LL
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr -> next;

    int count =0;

    while ( count < k)
    {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        count ++;
    }

    //! STEP B: Recursive call
    if (forward != NULL)
    {
        head -> next = reverseKNodes(k,forward);
    }

    //! Step C: Return Head of modified LL
    return prev;
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

    head = reverseKNodes(4, head);
    print(head);

    
    return 0;
}