// Deletion in BST
/*
 *1. Node tak pohchna hai
 *2. Delete krdo

 a. Leaf Node hai to delete krdo
 b. RIght child hai to parent to child se jod do

1. **Deleting a Leaf Node:** If the node to be deleted is a leaf node (has no children), simply remove it from the tree.

2. **Node with Only Right Child:** If the node to be deleted has only a right child, connect its parent directly to its right child.

3. **Node with Only Left Child:** Similarly, if the node has only a left child, connect its parent directly to its left child.

4. **Node with Both Children:** If the node to be deleted has both left and right children:
   - Find the node's in-order successor (the smallest node in its right subtree) or in-order predecessor (the largest node in its left subtree).
   - Replace the node to be deleted with its in-order successor/predecessor.
   - Delete the in-order successor/predecessor node from its original position.


*/

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
}

#include <iostream>
using namespace std;

int main()
{

    return 0;
}