#include <iostream>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(ListNode *&head)
{
    ListNode *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *curr = head;
    int len = 0;
    while (curr != NULL)
    {
        curr = curr->next;
        len++;
    }
    int pos = len - n;
    for (int i = 0; i < pos; i++)
    {
        curr = curr->next;
    }

    ListNode *toDelete = curr->next;
    curr->next = curr->next->next;
    delete toDelete;

    return head;
}

int main()
{

    ListNode *head = new ListNode(1);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(3);
    ListNode *fourth = new ListNode(4);
    ListNode *fifth = new ListNode(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;
    cout << "printing LL" << endl;
    print(head);

    head = removeNthFromEnd(head, 2);
    print(head);
    return 0;
}