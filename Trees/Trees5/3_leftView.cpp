#include <iostream>
#include <queue>
#include <map>
using namespace std;

/*
Left View using Recursion

Top View of the Tree:
Left -> HD -1
Right -> HD +1


har level ki first Node chahiye
root ko store kiya
left ki call maaro
new Level pe aate ho to ans store karlo
if ans exist for a level donot update it

Level and vector ka size same ho jayega

root level vector pass horha


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

void printLeftView(Node *root, vector<int> &ans, int level)
{
    // base case
    if (root == NULL)
        return;

    if (level == ans.size())
    {
        ans.push_back(root->data);
    }

    printLeftView(root->left, ans, level + 1);
    printLeftView(root->right, ans, level + 1);
}

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

int main()
{
    Node *root = NULL;
    root = buildTree();
    vector<int> ans;
    int level = 0;
    printLeftView(root, ans, level);

    cout << "Printing the answer " << endl;
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}
