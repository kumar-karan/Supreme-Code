#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node()
    {
        this -> data = 0;
        this -> next = NULL;
    }
    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
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
    cout<< endl;
}
//I want to insert a node right at the head of LL
void insertAtHead(Node* &head,Node* &tail, int data)
{
    if(head == NULL)
    {
        Node* newNode = new Node(data); 
        head = newNode;
        tail = newNode;
        return;
    }

    Node* newNode = new Node(data);
    newNode -> next = head;
    head = newNode;
}

void insertAtTail(Node* &head,Node* &tail, int data)
{
    /*
    ! 1. Handling empty case seperately
            *a. Make new node 
            *b. head, tail = newNode;
    ! 2. Else 
            *a . Make new Node 
            *b. tail ka next = new Node
            *c. Update tail = newNode
    */

    if(head == NULL)
    {
        Node* newNode = new Node(data); 
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data); 
    tail -> next = newNode;
    tail = newNode; //! important
}

int findlen(Node* head)
{
    int i =0;
    while (head != NULL)
    {
        head = head -> next;
        i++; 
    }
    return i;

}
//& Inserts us position ke baad 
void insertAtPosition( int position, Node* &head, Node* &tail, int data)
{
    /*
    * Empty case ko handle seperately 
    ! 1. Find Position { prev , current }
    ! 2. Create a node 
    ! 3. new node ka next = current
    ! 4. Prev ka next = newNode
    */

   if(head == NULL)
   {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
   }

    if (position == 0)
    {
        insertAtHead(head , tail, data);
        return;
    }

    int len = findlen(head);
    if( position >= len)
    {
        insertAtTail(head, tail, data);
        return;
    }

    int i =1;
    Node* prev = head;
    while ( i< position)
    {
        prev = prev -> next;
        i++;
    }
    Node* curr = prev -> next;

    Node * newNode = new Node(data);
    newNode -> next = curr;
    prev -> next = newNode;
}

// & Deletion of NODE 

void deleteNode(int position, Node*&head, Node*&tail)
{
    if( head == NULL)
    {
        cout << " Linked List is Empty"<< endl;
        return ;

    }
    if(position == 1)
    {
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete(temp);
        return;
    }
    int len = findlen(head);
    if(position >= len )
    {
        Node* prev = head;
        int i =1;
        while(i<position-1)
        {
            prev = prev -> next;
            i++;
        }

        prev -> next = NULL;
        Node* temp = tail;
        tail= prev;
        delete temp;
        return;
    }

    int i = 1;
    Node* prev = head;
    while(i< position-1)
    {
        prev = prev -> next;
        i++;
    }
    Node* curr = prev-> next;

    prev -> next = curr -> next;
    curr -> next = NULL;
    delete(curr);
}


int main()
{
    Node* head = NULL;
    Node* tail = head;


    insertAtHead(head,tail,20);
    insertAtHead(head,tail,50);
    insertAtHead(head,tail,60);
    insertAtHead(head,tail,90);

    // print(head);

    // while(tail-> next != NULL)
    //     tail = tail -> next;

    insertAtTail(head,tail,20);
    insertAtTail(head,tail,50);
    insertAtTail(head,tail,60);
    // insertAtTail(head,tail,90);

    print(head);
    /*

    cout << "Head: "<< head -> data << endl;
    cout << "Tail: " << tail -> data << endl<< endl;

    insertAtPosition(7, head, tail ,101);

    print(head);
    cout << "Head: "<< head -> data << endl;
    cout << "Tail: " << tail -> data << endl<< endl;

    */


   deleteNode(7,head,tail);
   print(head);

    return 0;
}