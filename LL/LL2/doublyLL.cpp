#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* prev;
    Node* next;

    Node()
    {
        this-> data = 0;
        this -> prev = NULL;
        this -> next = NULL;
    }
    Node(int data)
    {
        this-> data = data;
        this -> prev = NULL;
        this -> next = NULL;
    }
    ~Node()
    {
        cout << "Node with value "<< this -> data << " deleted"<<endl; 
    }
};

void print(Node* &head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}
int getLength(Node* head)
{
    int len =0;
    Node* temp = head;

    while(temp != NULL)
    {
        temp = temp -> next;
        len++;
    }
    return len;
}

void insertAtHead(Node* &head, Node* &tail, int data)
{
    Node* newNode = new Node(data);
    if( head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode -> next = head;
    head -> prev = newNode;
    head = newNode;
}

void insertAtTail(Node* &head, Node* &tail, int data)
{
    Node* newNode = new Node(data);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail -> next = newNode;
    newNode -> prev = tail;
    tail = newNode;
}

void insertAtPosition(int position, Node* &head, Node* &tail, int data)
{
    /*
    *1. Find Prev and current 
    *2. Create a node
    *3. prevNode ka next = newNode
    *4. newNode ka prev = prevNode
    *5. curr -> prev = newNode;
    *6. newNode ka next curr pe
    */

    if( head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    if(position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }
    if(position > getLength(head))
    {
        insertAtTail(head,tail,data);
        return;
    }

    Node* newNode = new Node(data);
    Node* prevNode = head;

    int i=1;
    while(i< position-1)
    {
        prevNode = prevNode->next;
        i++;
    }

    Node* curr = prevNode -> next;

    prevNode -> next = newNode;
    newNode -> prev = prevNode;
    curr -> prev = newNode;
    newNode -> next = curr;



}

void deleteNode(int position, Node* &head, Node* &tail)
{
    int len = getLength(head);
    if(position > len)
    {
        cout << " Enter Valid Position" << endl;
        return;
    }
    if(head == NULL)
    {
        cout << " Link List is empty " << endl;
        return;
    }
    if ( head -> next == NULL)
    {
        // Single node 
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }
    if ( position == 1 )
    {
        Node* temp = head;
        head = head -> next;
        head -> prev = NULL;
        temp -> next = NULL;
        delete temp;
        return;
    }
    if(position == len)
    {
        // delete last node
        Node* temp = tail;
        tail = tail -> prev;
        temp -> prev = NULL;
        tail -> next = NULL;
        delete (temp);
        return;
    }

    // *1 Find left, curr, right
    int i=1;
    Node*left = head;
    while(i< position-1)
    {
        left = left -> next;
        i++;
    }
    Node* curr = left -> next;
    Node* right = curr -> next;

    left-> next = right;
    right-> prev = left;

    curr-> next = NULL;
    curr-> prev = NULL;

    delete(curr);


}

int main()
{
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    first -> next = second;
    second -> prev = first;

    second -> next = third;
    third -> prev = second;

    Node* head = first;
    Node* tail = third;


    insertAtHead(head,tail,50);

    // print(head);

    insertAtTail(head, tail , 101);
    // print(head);

    insertAtPosition(5, head, tail, 401);
    print(head);

    deleteNode(3,head,tail);
    print(head);


    
    return 0;
}