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
void incremenr(Node*head)
{
    Node*temp = head;
    while(temp != NULL)
    {
        temp -> data ++;
        temp = temp -> next;
    }
}

int main()
{
    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    n1 -> next = n2;
    incremenr(n1);
    print(n1);

    return 0;
}