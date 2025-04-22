// make tree from preorder vector // Done
// preorder tree traversal // Done
// inorder tree traversal // Done
// postorder tree traversal // Done

#include <iostream>
#include <vector>
#include <queue>
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

static int idx = -1;

BinaryTreeNode *makeTree(vector<int> preOrderTree)
{
    idx++;

    if (preOrderTree[idx] == -1)
        return NULL;

    BinaryTreeNode *root = new BinaryTreeNode(preOrderTree[idx]);
    root->left = makeTree(preOrderTree);
    root->right = makeTree(preOrderTree);

    return root;
};

void preOrderTreeTraversal(BinaryTreeNode *root)
{
    if (root == NULL)
        return; // jese hi null milega return ho jaeygga

    cout << root->data << "  ";
    preOrderTreeTraversal(root->left);
    preOrderTreeTraversal(root->right);
};

void inOrderTreeTraversal(BinaryTreeNode *root)
{
    if (root == NULL)
        return;

    inOrderTreeTraversal(root->left);
    cout << root->data << " ";
    inOrderTreeTraversal(root->right);
}

void postOrderTreeTraversal(BinaryTreeNode *root)
{
    if (root == NULL)
        return;

    postOrderTreeTraversal(root->left);
    postOrderTreeTraversal(root->right);
    cout << root->data << " ";
}

void levelOrderTreeTraversal(BinaryTreeNode *root)
{
    queue<BinaryTreeNode *> q;

    q.push(root);

    while (!q.empty())
    {
        BinaryTreeNode *temp = q.front();

        cout << temp->data << " ";
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
}
int main()
{
    // Your code here
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    BinaryTreeNode *root = makeTree(preOrder);
    preOrderTreeTraversal(root);
    cout << "\n";
    inOrderTreeTraversal(root);
    cout << "\n";
    postOrderTreeTraversal(root);
    cout << "\n";
    levelOrderTreeTraversal(root);
    return 0;
}