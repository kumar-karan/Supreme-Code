#include<iostream>
#include<queue>
using namespace std;

/*
* Height of tree or MAX Depth ->No. of Nodes from Farthest Path from root Node to Leaf node
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

void levelOrderTraversal(Node* root)
{
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        //A
        Node* temp = q.front();
        q.pop();
        if(temp == NULL)
        {
            cout << endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp -> data << " ";

            if(temp -> left)
                q.push(temp->left);
            if(temp -> right)
                q.push(temp-> right);
        }
    }
    
}


int treeHeight(Node* root)
{
    if(root == NULL)
        return 0;

    int leftHeight = treeHeight(root -> left);
    int rightHeight = treeHeight(root -> right);
    int ans = max(leftHeight, rightHeight) + 1;
    return ans;
}

int main()
{
    Node* root = NULL;

    root = buildTree();
    levelOrderTraversal(root);
    cout << "Height : "<<treeHeight(root) << endl;
    
    return 0;
}