#include <iostream>
#include <queue>
#include <map>

using namespace std;

/*
Level Order traversal

Top View of the Tree:
Left -> HD -1
Right -> HD +1

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
void printTopView(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    // create a map for storing horizontal distance and data for top node
    map<int, int> topNode;

    // we will store a pair consisting of Node and Horizontal Distance
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second;

        // jo bhi horizontal distance aaya hai, check if ans for that HD already exists or not
        if (topNode.find(hd) == topNode.end())
        {
            // create entry
            topNode[hd] = frontNode->data;
        }
        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }

    // answer will be stored in the MAP

    cout << "Printing the answer" << endl;

    for (auto i : topNode)
    {
        cout << i.first << " -> " << i.second << endl;
    }
}

int main()
{
    Node *root = NULL;
    root = buildTree();

    printTopView(root);
    return 0;
}