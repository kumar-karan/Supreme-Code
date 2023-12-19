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

Node* remove_duplicate_unsorted(Node* &head)
{

    if(head == NULL)
    {
        return NULL;
    }
    if(head -> next == NULL)
    {
        return head;
    }

    Node* temp = head; 
    while(temp!= NULL)
    {
        Node* curr = temp -> next;
        Node* prev = temp;
        while(curr != NULL)
        {
            if(curr-> data == temp -> data )
            {
                Node* del = curr;
                prev -> next = curr -> next;
                curr = curr -> next;
                del -> next = NULL;
                delete del;
            }
            else
            {
                prev = curr;
                curr = curr -> next;
            }
        }

        temp = temp -> next;
    }

    return head;

}

// void remove2(Node* head)
// {
//     if(head == NULL)
//     {
//         cout << " LL is empty "<< endl;
//         return;
//     }
//     if( head -> next == NULL)
//     {
//         return;
//     }

//     Node* temp = head;
//     while( temp != NULL)
//     {
//         Node* curr = temp-> next;
//         Node* prev = temp;

//         while(curr != NULL)
//         {
//             if( temp -> data == curr -> data)
//             {
//                 prev -> next = curr -> next;
//                 Node* del = curr;
//                 curr = curr -> next;
//                 del -> next = NULL; delete del;
//             }
//             else
//             {
//                 prev = curr;
//                 curr = curr -> next;
//             }
//         }
//         temp = temp -> next;
//     }
// }

void print (Node* &head)
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
    Node* head = new Node(20);
    Node* second = new Node(20);
    Node* third = new Node(20);
    Node* fourth = new Node(20);
    Node* fifth = new Node(20);
    Node* sixth = new Node(20);
    Node* seventh = new Node(20);

    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = fifth;
    fifth -> next = sixth;
    sixth -> next = seventh;

    print(head);

    head = remove_duplicate_unsorted(head);

    print(head);


    return 0;
}