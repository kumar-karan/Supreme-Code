#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
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

void printKthFromEnd(Node *&head, int &n)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    n = len - n-1;
    if (head == NULL || head->next == NULL || n == 0)
        cout << head->data;

    Node* curr = head;
    while (n --)
    {
        curr = curr->next;
    }

    cout << curr->data << endl;
}
int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    cout << "printing Kth node from the end" << endl;
    int k = 2;
    printKthFromEnd(head, k);

    return 0;
}

