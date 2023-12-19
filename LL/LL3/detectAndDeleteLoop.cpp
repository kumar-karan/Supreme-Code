/*
! 1. Check loop is present in LL or not 
! 2. Starting point of Loop
! 3. Remove Loop 
*/

/*
*1. Find Loop is present or not
*2. Use Map in this question

*3. Second Method is Floyd Cycle Detection
    *a. Slow fast lagana hota hai 
    *b. Fast ko do step chalao; Slow ko ek step chalao
    *c. If slow = fast  ----> Loop present 
    *d. fast == NULL -----> Loop absent

    * with each pass in loop the distance bw fast and slow is getting reduced by 1
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
// ! 1. Checking for Loops 
bool checkForLoops(Node* &head)
{
    if(head == NULL)
    {
        cout << " LL is Empty"<<endl;
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL)
    {
        fast = fast -> next;
        if (fast != NULL)
        {
            fast = fast -> next;
            slow = slow -> next;
        }
        if(slow == fast)
        {
            return true ;
        }
    }
    // fast null hogya
    return false;
}

// ! 2. Starting Point of loop 
/*
    *a Slow or fast meet karao
    *b slow ko head karo
    *c slow or fast ko ek ek aage karo jabtk slow = fast 
    *d jis point pe meet karega wo starting point hoga 
    *e why (proof)?

        a = start se loop start tak
        b = loop start se slow fast meet ka point 
        c = slow fast se loop start  // basically humara cycle 
            loop start se loop start 

        Distance travelled by fast = 2* distance travelled by slow

       ~ a + xc + b = 2* (a + yc + b)
       ~ (x-2y) c = a+b\
       ~ let x-2y = k
       ~ a+b = kc
       ~  
          
    !  slow start se loop start tak jayega tabtk fast meet point se loop start tak aajayega A travel krke 
*/

Node* startingPointLoop(Node* head)
{
    if(head == NULL)
    {
        return head;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL)
    {
        fast = fast -> next;
        if(fast != NULL)
        {
            fast = fast -> next;
            slow = slow -> next;
        }

        if(slow == fast)
        {
            slow = head;
            break;
        }
    }
    while(slow != fast )
    {
        slow = slow -> next;
        fast = fast -> next;
    }

    return slow;
}

Node* removeLoop(Node* &head)
{
        if(head == NULL)
    {
        return head;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL)
    {
        fast = fast -> next;
        if(fast != NULL)
        {
            fast = fast -> next;
            slow = slow -> next;
        }

        if(slow == fast)
        {
            slow = head;
            break;
        }
    }
    Node* prev = fast;
    while(slow != fast )
    {
        prev =fast;
        slow = slow -> next;
        fast = fast -> next;
    }
    prev -> next = NULL;

    return slow;

}

int main()
{

    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    Node* seventh = new Node(70);
    Node* eighth = new Node(80);
    Node* ninth = new Node(90);
    // Node* tenth = new Node(60);

    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = fifth; 
    fifth -> next = sixth;
    sixth -> next = seventh;
    seventh -> next = eighth;
    eighth -> next = ninth;
    ninth -> next = fifth;

    // print(head);
    
    if(checkForLoops(head))
        cout << "Loop is present"<< endl;
    else 
        cout << "Loop is not present " << endl;

    // cout << " Loop is present or not = " << checkForLoops(head) << true;

    cout << "Starting point of loop " << startingPointLoop(head) -> data << endl;

    removeLoop(head);
    
    print(head);
    if(checkForLoops(head))
        cout << "Loop is present"<< endl;
    else 
        cout << "Loop is not present " << endl;        
    return 0;
}