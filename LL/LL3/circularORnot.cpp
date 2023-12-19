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

void circularOrNot(Node* &head)
{
    /*
    *1. temp = head
    *2. Forward Move karte jaao and check ki head wapas milta hai ki ni 
    *3. jbtk temp null na hojaye
    */

   Node* temp = head;
   while(temp != NULL)
   {
        if(temp == NULL)
        {
            cout << "Circular Linked List"<< endl;
            return;
        }
        else
        {
            cout<< "Not a circular Linked List" << endl;
            return;
        }
   }
}

int main()
{

    
    return 0;
}