// Q1) we can implement the function in which we check that tree is identical or not // Done

// Q1) start
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
BinaryTreeNode *makeTree(const vector<int> &v)
{
    idx++;
    if (v[idx] == -1)
        return NULL;
    BinaryTreeNode *root = new BinaryTreeNode(v[idx]);
    root->left = makeTree(v);
    root->right = makeTree(v);
    return root;
}

void preOrderTreeTraversal(BinaryTreeNode *root)
{
    if (root == NULL)
        return; // jese hi null milega return ho jaeygga

    cout << root->data << "  ";
    preOrderTreeTraversal(root->left);
    preOrderTreeTraversal(root->right);
};

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

bool isTreeIdentical(BinaryTreeNode *root1, BinaryTreeNode *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;  //agr dono root jo function ky pass aai hyn wo same hyn to true return  krdega; 
    }
    if (root1 ==NULL || root2 ==NULL ){
        return false; //agr 1 node null hy or dusri null nhi to false return krdega (agr dono null hui to uppr wali condition hi direct true return krdegi)
    }
    bool isLeftIdentical = isTreeIdentical(root1->left, root2->left);
    bool isRightIdentical = isTreeIdentical(root1->right, root2->right);
    return root1->data == root2->data && isLeftIdentical && isRightIdentical;
}

int main()
{
    /* this is a tree 1 */
    idx = -1;
    vector<int> preOrder1 = {1, 7, 2, -1, -1, 6, 5, -1, -1, 11, -1, -1, 9, -1, 9, 5, -1, -1, -1};
    BinaryTreeNode *rootOfTree1 = makeTree(preOrder1);
    // preOrderTreeTraversal(rootOfTree1);
    // levelOrderTreeTraversal(rootOfTree1);

    /* this is a tree 2 */
    idx= -1; // jb dusra tree formend ho rha hy to static variable to pta nhi kya ho chuka hy (pichly tree formed hony ki wja sy)
    vector<int> preOrder2 = {1, 7, 2, -1, -1, 6, 5, -1, -1, 11, -1, -1, 9, -1, 9, 5, -1, -1, -1};
    BinaryTreeNode *rootOfTree2 = makeTree(preOrder2);

    if (isTreeIdentical(rootOfTree1, rootOfTree2))
    {
        cout << "these 2 trees are identical. \n";
    }
    else
    {
        cout << "these two trees are not identical. \n";
    }
}

// Q1) end