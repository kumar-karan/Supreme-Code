#include <iostream>
#include <queue>
using namespace std;
/*
* inorder ->  40 20 10 50 30 60 -> LNR
* postorder-> 40 20 50 60 30 10 -> LRN

10 ki root node bana li
post --
L R N = Node ke left me node ka right hoga
30 (10 NODE ) ke right me ayega
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
        this->left = NULL;
        this->right = NULL;
    }
};
int findPosition(int arr[], int n, int element)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
            return i;
    }
    return -1;
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        // A
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp->data << " ";

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

Node *buildTreeFromInOrderPostOrder(int inorder[], int postorder[], int &postIndex, int size, int inorderStart, int inorderEnd)
{

    // base case
    if (postIndex < 0 || inorderStart > inorderEnd)
    {
        return NULL;
    }

    int element = postorder[postIndex];
    postIndex--;
    Node *root = new Node(element);

    int pos = findPosition(inorder, size, element);

    root->right = buildTreeFromInOrderPostOrder(inorder, postorder, postIndex, size, pos + 1, inorderEnd);
    root->left = buildTreeFromInOrderPostOrder(inorder, postorder, postIndex, size, inorderStart, pos - 1);

    return root;
}

int main()
{
    int inorder[] = {40, 20, 10, 50, 30, 60};
    int postorder[] = {40, 20, 50, 60, 30, 10};
    int size = 6;
    int postIndex = size - 1;
    ;
    int inorderStart = 0;
    int inorderEnd = size - 1;

    cout << "Building the Tree : " << endl;
    Node *root = buildTreeFromInOrderPostOrder(inorder, postorder, postIndex, size, inorderStart, inorderEnd);
    cout << "Printing the Tree : " << endl;
    levelOrderTraversal(root);

    return 0;
}