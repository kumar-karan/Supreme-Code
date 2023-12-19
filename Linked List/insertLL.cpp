#include<bits/stdc++.h>
using namespace std;


class Node 
{
    public : 
    int data;
    Node * next;

    Node ()
    {
        this -> data = 0;
        this -> next = NULL;
    }
    Node (int data)
    {
        this -> data = data;
        this -> next = NULL;

    }

    // write a destructor to delete a node
    ~Node()
    {
        cout << " Node with Value : " << this -> data << "deleted" << endl;
    }
    

};

void printLL(Node* head)  // void printll(Node* &head)
{
    Node* temp = head;
    while ( temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}
int findlength(Node* head)
{
    int len;
    while(head != NULL )
    {
        len ++;
    }
    return len;
}

void insertAtHead( Node* &head, Node* &tail, int data) // reference pass to change at origin
{
    Node* newNode = new Node(data);
    newNode -> next = head;
    if ( head == NULL)
    {
        tail = newNode;
    }
    head = newNode;

}

void insertAtTail ( Node* &head, Node* &tail, int data)
{
    Node* newNode = new Node(data);

    if(tail ==  NULL)
    {
        // LL is empty
        tail = newNode;
        head = newNode;
    }
    else 
        tail -> next = newNode;
    newNode -> next = NULL;
    // if(head == NULL)
    //     head = newNode;
    tail = newNode;
}

void insertAtPosition(int position, Node* &head, Node* &tail, int data)
{
    if(head == NULL )
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    Node* prev =head;
    if( position == 0 )
    {
        insertAtHead(head, tail, data);
        return;
    }
    int len = findlength(head);
    if( position >= len )
    {
        insertAtTail(head, tail, data);
        return;   
    }
    
    //find the position 
    for(int i = 1; i< position; i++ )
    {
        prev = prev -> next;
    }
    Node* curr = prev -> next;

    Node* newNode = new Node(data); 
    newNode -> next = curr;
    prev->next = newNode;

}

void deleteNode(int position, Node* &head, Node* &tail)
{
    if(head == NULL)
    {
        cout<< " Empty";
        return;
    }
    if(position == 1)
    {
        Node* temp = head;
        head = head-> next;
        temp -> next = NULL;
        delete temp;

        return;
    }
    int len = findlength(head);
    if(position==len)
    {
        //find previous 
        //previous -> NULL
        //Temp = tail
        // tail == prev;
        // delete temp
        int i=1;
        Node* prev = head;
        while(i< position -1 )
        {
            prev = prev -> next;
            i++;
        }

        prev -> next = NULL;
        Node*temp = tail;
        tail = prev;
        delete temp;

        return;

    }
}



int main ()
{

    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,40);
    insertAtHead(head,tail,50);
    insertAtHead(head,tail,60);
    insertAtTail(head, tail, 77);

    printLL(head);
    cout <<endl;
    // cout<<endl;
    // insertAtPosition(0, head, tail, 101);
    // printLL(head);
    // cout<<endl;

    // insertAtPosition(6,head,tail,99);
    // printLL(head);

    deleteNode(1, head ,tail);
    printLL(head);
    


    return 0; 
}