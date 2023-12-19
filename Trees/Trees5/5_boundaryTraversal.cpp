#include <iostream>
#include <queue>
#include <map>
using namespace std;

/*

left most node print kara do
leaf nodes print kara do
right most print kara  do


Jis node pe khade ho consider karo
Left jate jaao leaf node tak
NLR order

 */
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree()
{
    int data;
    // cout << "Enter the Data: " << endl;
    cin >> data;

    if (data == -1)
        return NULL;

    // STEP A, B, C

    Node *root = new Node(data);

    // cout << "Enter Data for Left part of " << data << " node" << endl;
    root->left = buildTree();
    // cout << "Enter Data for Right part of " << data << " node" << endl;
    root->right = buildTree();

    return root;
}

void printLeftBoundary(Node *root)
{
    // base case -> if root is NULL or a LEAF NODE then GO BACK
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
        return;

    // processing current node
    cout << root->data << " ";
    if (root->left)
        printLeftBoundary(root->left);
    else
        printLeftBoundary(root->right);
}

void printLeafBoundary(Node *root)
{
    // Base case
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        cout << root->data << " ";

    printLeafBoundary(root->left);
    printLeafBoundary(root->right);
}

void printRightBoundary(Node *root)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
        return;

    if (root->right)
        printLeftBoundary(root->right);
    else
        printLeftBoundary(root->left);
    // processing current node
    cout << root->data << " ";
}

void boundaryTraversal(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";

    // A
    printLeftBoundary(root->left);

    printLeafBoundary(root);

    printRightBoundary(root->right);
}

int main()
{
    Node *root = NULL;
    root = buildTree();

    boundaryTraversal(root);
    return 0;
}

// 10 20 30 -1 -1 50 70 90 -1 -1 80 -1 -1 60 -1 -1 40 -1 100 -1 120 110 -1 -1 130 -1 -1