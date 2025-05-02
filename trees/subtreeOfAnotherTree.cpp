// Q1) this is code in which check that is one tree a subtree of another tree

#include <iostream>
#include <vector>
using namespace std;

class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

// it is the function that makes tree and return root node
static int idx = -1;
BinaryTreeNode *makeTree(const vector<int> &preOrderTree)
{

    idx++;
    if (preOrderTree[idx] == NULL)
    {
        return NULL;
    }
    BinaryTreeNode *root = new BinaryTreeNode(preOrderTree[idx]);
    root->left = makeTree(preOrderTree);
    root->right = makeTree(preOrderTree);
    return root;
}

bool isTreeIdentical(BinaryTreeNode *root1, BinaryTreeNode *root2)
{
    if (root1 == NULL || root2 == NULL)
    {
        return root1 == root2;
    }

    bool isleftIdentical = isTreeIdentical(root1->left, root2->left);
    bool isRightIdentical = isTreeIdentical(root1->right, root2->right);

    return root1->data == root2->data && isleftIdentical && isRightIdentical;
}

bool isSubtree(BinaryTreeNode *root, BinaryTreeNode *subRoot)
{
    if (!subRoot) {
        return true; // An empty tree is always a subtree
    }
    if (!root) {
        return false; // Non-empty subtree cannot be found in an empty tree
    }
    if (isTreeIdentical(root, subRoot)) {
        return true; // Check if the current trees are identical
    }
    // Recursively check left and right subtrees
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main()
{
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    BinaryTreeNode *root = makeTree(preOrder);
}