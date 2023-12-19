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

int main()
{
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(20);
    Node* sixth = new Node(20);
    Node* seventh = new Node(10);

    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = fifth;
    fifth -> next = sixth;
    sixth -> next = seventh;

    print(head);

    return 0;
}