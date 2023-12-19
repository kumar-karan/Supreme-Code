// ! CHECK WHETHER THE Linked List is PALINDROME 
/*
! Approach
*1. Find Middle
*2. Reverse LL after middle node
*3. Start comparing both halves 
*/
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

Node* reverse (Node* &head )
{
    Node* prev = NULL;
    Node* curr = head;
    Node* next = curr -> next;

    while (curr != NULL)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

bool checkPalindrome(Node* &head)
{
    if(head == NULL)
    {
        cout << "LL is empty"<< endl;
        return true;
    }
    if(head-> next == NULL)
    { // single element
        return true;
    }

    // > 1 Node

    // * a. Find the middle node;

    Node* slow = head;
    Node* fast = head -> next;
    
    while(fast != NULL)
    {
        fast = fast -> next;
        if(fast != NULL)
        {
            fast = fast -> next;
            slow = slow -> next;

        }
    }
    // *b. reverse slow ke baad ka / middle kebaad ka 

    Node* reverseLLkahead = reverse(slow -> next);

    slow -> next = reverseLLkahead;

    //  * c. Start Comaparison 

    Node* temp1 = head;
    Node* temp2 = reverseLLkahead;

    while(temp2 != NULL)
    {
        if(temp1 -> data != temp2-> data)
        {
            return false;
        }
        else
        {
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
    }
    return true;
}


int main()
{

    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(30);
    Node* fifth = new Node(20);
    Node* sixth = new Node(10);

    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = fifth;
    fifth -> next = sixth;

    bool isPalindrome = checkPalindrome(head);

    if(isPalindrome)
        cout << "Valid Palindrome"<< endl;
    else
        cout << "Not a Valid Palindrome" << endl; 

    return 0;
}