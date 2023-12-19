#include<bits/stdc++.h>
using namespace std;


class node 
{
    public : 
    int data;
    node * next;

    node ()
    {
        this -> data = 0;
        this -> next = NULL;
    }
    node (int data)
    {
        this -> data = data;
        this -> next = NULL;

    }

};

void printll(node* head)  // void printll(node* &head)
{
    node* temp = head;
    while ( temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }

}

int main ()
{
    node* first = new node(10);
    node* second = new node(20);
    node* third = new node(30);
    node* fourth = new node(40);
   
    first -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = NULL;


    cout << "Printing Linked List :" << endl;
    printll(first);




    return 0; 
} 