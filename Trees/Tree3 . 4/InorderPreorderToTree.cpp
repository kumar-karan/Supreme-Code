#include<iostream>
#include<queue>
using namespace std;

/*
Inorder and Preorder diya hai input me usse postorder ya tree banana hai 

* Inorder : 3,1,4,5,2  -> LNR
* Preorder: 5,1,3,4,2  -> NLR

preorder ka sbse pehla node root hoga
5 ke left me 3 1 4
pre order me sbse pehle 1 aarha hai 
1 ki node banegi 
inorder me 
1 ke left me 3 hai and right me 4 hai 

*/

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
        
    }
};

int findPosition(int arr[],int n, int element)
{
    for(int i =0; i<n; i++)
    {
        if(arr[i] == element)
            return i;
    } 
    return -1;
}

Node* buildTreeFromPreOrderInOrder(int inorder[], int preorder[], int size, int &preIndex,int inorderStart, int inorderEnd)
{
    //base case
    if(preIndex >= size || inorderStart > inorderEnd)
    {
        return NULL;
    }
    int element = preorder[preIndex++];

    Node* root = new Node(element);

    int pos = findPosition(inorder, size, element);

    // Step B : root -> left solve
    root -> left = buildTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, inorderStart, pos-1 );
    root -> right = buildTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, pos+1, inorderEnd );
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

int main()
{

    int inorder[] = {40,20,50,10,60,30,70};
    int preorder[]= {10,20,40,50,30,60,70};
    int size = 7;
    int preIndex = 0;
    int inorderStart = 0;
    int inorderEnd = size-1;   

    Node* root = buildTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, inorderStart, inorderEnd); 

    cout <<"Printing Level order traversal" << endl;
    levelOrderTraversal(root);
    return 0;
}