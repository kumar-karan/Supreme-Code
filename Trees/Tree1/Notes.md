Tree is Data Structure 
Non Linear Data Structute

Node 
Root 
Parent 
Child 
Ancestor 
Descendant
Sibling 
leaf 


Code:

class Node
{
   int data;
   node* left;
   node* rightl

};


for nary 

class node
{
   int data;
   vector<node*> child;
}

        1
       / \
      2   3
     / \
    4   5

Types Of questions 

1. Online Test
   MCQ -> easy or formula based - 2n+1 type 
   Coding Question -> 95% classical question or similar level question
      both in interview or coding test
   5% ques can be tough -> Tree, heap, map -> where multiple concept are being asked 


1. **Introduction to Trees**:
   - A tree is a hierarchical data structure consisting of nodes connected by edges.
   - It is a special type of graph with no cycles, which means there is only one path between any two nodes.

2. **Tree Terminology**:
   - **Node**: A fundamental unit of a tree, which stores data and has zero or more child nodes.
   - **Root**: The topmost node in a tree, from which all other nodes are descended.
   - **Leaf**: A node with no children, i.e., a node at the end of a branch.
   - **Parent**: A node that has one or more child nodes.
   - **Child**: A node that is a direct descendant of another node.
   - **Siblings**: Nodes that share the same parent.
   - **Depth**: The level of a node in the tree, with the root node at depth 0.
   - **Height**: The length of the longest path from a node to a leaf.

3. **Binary Trees**:
   - A binary tree is a tree in which each node can have at most two children, often referred to as the left child and the right child.
   - Special types of binary trees include binary search trees (BSTs) where the left child is smaller than the parent, and the right child is larger.

        1
      / | \
     2  3  4
    / \   \
   5   6   7


In this N-ary tree:
- Node 1 is the root.
- Node 2, 3, and 4 are children of Node 1.
- Node 2 has two children, Node 5 and Node 6.
- Node 4 has one child, Node 7.

This is just a basic representation of an N-ary tree, where each node can have a variable number of children. In practice, N-ary trees can have more complex structures with different numbers of children for each node.


   
4. **Tree Traversal**:
   - Tree traversal is the process of visiting and processing all nodes in a tree.
   - Common traversal algorithms:
     - **In-order**: Visit left subtree, visit the current node, visit right subtree (used for BSTs to get sorted output).
     - **Pre-order**: Visit the current node, visit left subtree, visit right subtree (used for creating a copy of the tree).
     - **Post-order**: Visit left subtree, visit right subtree, visit the current node (used for deleting a tree).

5. **Binary Heap**:
   - A binary heap is a binary tree with special properties, often used to implement priority queues.
   - Min-heap: The value of each node is smaller than or equal to the values of its children.
   - Max-heap: The value of each node is greater than or equal to the values of its children.

6. **Balanced Binary Trees**:
   - Balanced trees, like AVL trees and Red-Black trees, ensure that the tree remains relatively balanced, resulting in efficient operations.
   - AVL trees: Ensure the balance factor (height difference between left and right subtrees) of each node is at most 1.
   - Red-Black trees: Ensure the tree remains approximately balanced and have specific rules for coloring nodes to maintain balance.

7. **Tree Applications**:
   - Trees are used in various applications, such as:
     - Hierarchical data representation (file systems, organization charts).
     - Searching and sorting (binary search trees).
     - Expression parsing and evaluation.
     - Game trees (e.g., in chess AI).
     - Network routing algorithms (e.g., OSPF).

8. **Tree Operations**:
   - Insertion: Adding a new node to the tree while maintaining its properties.
   - Deletion: Removing a node from the tree while maintaining its properties.
   - Searching: Finding a specific node or element in the tree.
   - Updating: Modifying the value of a node.

These are some fundamental concepts and notes on trees in data structures and algorithms. Trees play a crucial role in various applications, and understanding them is essential for solving many algorithmic problems.