#include<iostream>
using namespace std;

/* 
*1. Creating Using Level Order Traversal
*2. Recursively -> a. Root Node ||  b. Root ka left recursion karega. || c. Right part bhi recursion karega 

~   20 30 50 -1 60 -1 -1 40 -1 -1 100 -1 -1

*/

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this-> data = data;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree()
{
    int data;
    cout <<"Enter the Data: " << endl;
    cin >> data;

    if(data == -1)
        return NULL;
    
    // STEP A, B, C

    Node* root = new Node(data);

    cout <<"Enter Data for Left part of " << data << " node" << endl;
    root -> left = buildTree();
    cout <<"Enter Data for Right part of " << data << " node" << endl;
    root -> right = buildTree();

    return root;
}

int main()
{
    Node* root = NULL;
    root = buildTree();

    
    return 0;
}