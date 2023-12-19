// ! Remove Duplicates from a Sorted LL

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
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void removeDuplicateSorted ( Node* &head)
{
    if(head == NULL)
    {
        cout<< " LL is empty "<< endl;
        return;
    }
    if(head-> next == NULL)
    {
        cout<< " Single node"<< endl;
        return;
    }

    Node* curr= head;

    while(curr != NULL )
    {
        if( (curr -> next != NULL ) && (curr -> data == curr -> next -> data))
        {
            Node* temp = curr -> next;
            curr->next = curr-> next -> next;

            temp -> next = NULL;
            delete (temp);

        }
        else
        {
            curr = curr -> next;
        }
    }
}

int main()
{

    Node *head = new Node(10);
    Node *second = new Node(10);
    Node *third = new Node(10);
    Node *fourth = new Node(10);
    Node *fifth = new Node(40);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    print(head);
    removeDuplicateSorted (head);
    print(head);
    
    return 0;
}