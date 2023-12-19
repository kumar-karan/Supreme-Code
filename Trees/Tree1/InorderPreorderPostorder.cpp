#include<iostream>
#include<queue>
using namespace std;
/*
INORDER : LNR
PREORDER : NLR 
POSTORDER : LRN
*/

struct Node {
    int data;
    Node* left;
    Node* right;
};

void inorderTraversal(Node* root)
{
    // basecase 
    // LNR 
    if(root == NULL)
    {
        return;
    }    
    inorderTraversal(root -> left);
    cout  << root ->  data << " ";
    inorderTraversal(root -> right);
}

void preorderTraversal(Node* root)
{
    // NLR 
    if(root == NULL)
        return;
    cout << root-> data <<" ";
    preorderTraversal(root -> left);
    preorderTraversal(root -> right);
}

void postorderTraversal(Node* root)
{
    // LRN 
    if(root == NULL)
        return;
    postorderTraversal(root -> left);
    postorderTraversal(root -> right);
    cout << root -> data << " ";
}
int main()
{
    
    return 0;
}