// make tree from preorder vector // Done
// preorder tree traversal // Done
// inorder tree traversal // Done
// postorder tree traversal // Done
// level order tree traversal // Done

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
    q.push(NULL);

    while (!q.empty())
    {
        BinaryTreeNode *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            if (!q.empty())
            {
                cout << endl;
                q.push(NULL);
                continue;
            }
            else
            {
                break;
            }
        };

        cout << curr->data << " ";

        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
}

int getHeightOfTree(BinaryTreeNode *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = getHeightOfTree(root->left);
    int rightHeight = getHeightOfTree(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int getNumOfNodesInTree(BinaryTreeNode* root){
    if (root ==NULL) return 0;

    int numOfLeftNodes = getNumOfNodesInTree(root->left);
    int numOfRightNodes = getNumOfNodesInTree(root->right);

    return (numOfLeftNodes+numOfRightNodes)+1;
}

int main()
{
    // Your code here
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    BinaryTreeNode *root = makeTree(preOrder);
    // preOrderTreeTraversal(root);
    // cout << "\n";
    // inOrderTreeTraversal(root);
    // cout << "\n";
    // postOrderTreeTraversal(root);
    // cout << "\n";
    // levelOrderTreeTraversal(root);

    cout << "the height of the tree is :" << getHeightOfTree(root) << endl;
    cout<<"the number of nodes in the tree is :" << getNumOfNodesInTree(root)<<endl;
    return 0;
}