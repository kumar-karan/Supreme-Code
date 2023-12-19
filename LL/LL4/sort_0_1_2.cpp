/*
! Sort 0s 1s and 2s 

*2  
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
    if ( head == NULL)
    {   cout<< "LL IS EMPTY "<<endl;
        return;
    }
        
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

Node* sort2(Node* head)
{

    if(head == NULL)
        return NULL;
    Node* zerohead = new Node(-1);
    Node* zerotail = zerohead;

    Node* onehead = new Node(-1);
    Node* onetail = onehead;

    Node* twohead = new Node(-1);
    Node* twotail = twohead;


    Node* curr = head;
    while(curr != NULL)
    {
        if(curr -> data == 0)
        {
            //* isolationg zero waali node 
            Node* temp = curr;
            curr = curr-> next;
            temp -> next = NULL;
            //* zerotail ke aage laga do 
            zerotail -> next = temp;
            zerotail = zerotail-> next;

            // delete(temp);
        }
        else if(curr -> data == 1)
        {
            //* isolationg one waali node 
            Node* temp = curr;
            curr = curr-> next;
            temp -> next = NULL;
            //* onetail ke aage laga do 
            onetail -> next = temp;
            onetail = onetail-> next;

            // delete(temp);
        }
        else if(curr -> data == 2)
        {
            //* isolationg two waali node 
            Node* temp = curr;
            curr = curr-> next;
            temp -> next = NULL;
            //* twotail ke aage laga do 
            twotail -> next = temp;
            twotail = twotail-> next;

            // delete(temp);
        }
    }

    // * zero one two ki LL ready hai 

    // remove dummy nodes 

    // join the nodes 

    Node* temp = onehead;
    onehead = onehead -> next;
    temp -> next = NULL;
    delete temp;

    temp = twohead;
    twohead = twohead -> next;
    temp -> next = NULL;
    delete temp;

    // join list 

    if(onehead != NULL)
    {
        zerotail -> next = onehead;
        if(twohead != NULL)
            onetail -> next = twohead;
    }
    else{
        if(twohead != NULL)
        {
            zerotail -> next = twohead;
        }
    }

    temp = zerohead;
    zerohead = zerohead -> next;
    temp -> next = NULL;
    
    return zerohead;
}



int main()
{

    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(2);
    Node *fourth = new Node(0);
    Node *fifth = new Node(0);
    Node *sixth = new Node(1);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    print(head);

    // sortZeroOneTwo(head);
    head = sort2(head);

    print(head);
    
    return 0;
}