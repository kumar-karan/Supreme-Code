#include <iostream>
#include <queue>
using namespace std;

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

Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        // tree was empty till NOW
        // this is the first node we have to create
        root = new Node(data);
        return root;
    }

    // not the first Node
    if (root->data > data)
    {
        // insert in left
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
        root->right = insertIntoBST(root->right, data);
    }

    return root; // Return the modified root
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
void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void preOrderTraversal(Node *root)
{ // NLR
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void inOrderTraversal(Node *root)
{ // LNR
    if (root == NULL)
        return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}
void postOrderTraversal(Node *root)
{ // LRN
    if (root == NULL)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

Node *findNodeInBST(Node *root, int target)
{
    if (root == NULL)
        return NULL;
    if (root->data == target)
        return root;

    if (root->data > target)
        return findNodeInBST(root->left, target);
    else
        return findNodeInBST(root->right, target);
}

int minVal(Node *root)
{
    Node *temp = root;
    if (temp == NULL)
        return -1;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

int maxVal(Node *root)
{
    Node *temp = root;
    if (temp == NULL)
        return -1;

    while (temp->right != NULL)
        temp = temp->right;
    return temp->data;
}

// Inorder predecessor means left subtree me max element;
// Node *InorderPredecessor(Node *root, int data)
// {
//     if (root == NULL)
//         return -1;

//     if (root->data == data)
//     {
//         int min;
//         min = maxVal(root->left);
//     }
// }

Node *InorderPredecessor(Node *root, Node *p)
{
    Node *pre = 0;
    Node *curr = root;

    while (curr)
    {
        if (curr->data < p->data)
        {
            pre = curr;
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }
    return pre;
}

Node *deleteNodeInBST(Node *root, int target)
{
    if (root == NULL)
        return root;

    // Step 1
    Node *temp = findNodeInBST(root, target);
    // I want to delete TEMP
    // WE have 4 cases
    if (temp->left == NULL && temp->right == NULL)
    {
        // Leaf Node
        delete temp;
        return NULL;
    }
    else if (temp->left == NULL && temp->right != NULL)
    {
        Node *child = temp->right;
        delete temp;
        return child;
    }
    else if (temp->left != NULL && temp->right == NULL)
    {
        Node *child = temp->left;
        delete temp;
        return child;
    }
    else // both child exists
    {
        // inorder predecessor of left subtree -> left sub tree me max Val
        Node *child = InorderPredecessor(root, temp);
        temp->data = child->data;
        bool aageKaAns = deleteNodeInBST(temp->left, child->data);
        return temp;
    }
}

Node *deletefromBST(Node *root, int target)
{
    if (root == NULL)
        return root;

    Node *targetNode = findNodeInBST(root, target);
}

int main()
{
    Node *root = NULL;
    cout << "Enter the Data for Node" << endl;
    takeInput(root);
    cout << "Printing the tree using level order traversal:" << endl;
    levelOrderTraversal(root);
    cout << endl;
    // cout << "Printing Inorder: ";
    // inOrderTraversal(root);
    // cout << endl;
    // cout << "Printing Pre-order: ";
    // preOrderTraversal(root);
    // cout << endl;
    // cout << "Printing Post-order: ";
    // postOrderTraversal(root);
    // cout << endl;
    // cout << "Minumum Value of BST: " << minVal(root) << endl
    //      << endl;
    // cout << "Max Value of BST: " << maxVal(root) << endl
    //      << endl;

    deleteNodeInBST(root, 100);
    levelOrderTraversal(root);

    return 0;
}

// 100 50 150 40 60 175 110 - 1