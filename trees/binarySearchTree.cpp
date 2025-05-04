

#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

/*THIS IS THE BLUE PRINT OF THE NODE IN THE TREE*/
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

/*THIS FUNCTION INSERT THE NODE IN THE TREE AND RETURN THE ROOT NODE OF THE TREE*/
BinaryTreeNode *insertBST(BinaryTreeNode *root, int val)
{
    if (!root)
    {
        return new BinaryTreeNode(val);
    }

    if (val >= root->data)
    {
        root->right = insertBST(root->right, val);
    }
    else
    {
        root->left = insertBST(root->left, val);
    }

    return root;
}

/* THIS FUNCTION MAKE TREE FROM VECTOR USING INSERT FUNCTION */
BinaryTreeNode *buildBSTFromVector(const vector<int> &v)
{
    BinaryTreeNode *root = NULL;

    for (int i = 0; i < v.size(); i++)
    {
        root = insertBST(root, v[i]);
    }

    return root;
}

/* FUNCTION THAT TAKES NUMBER AS PARAMETER AND CHECK IF IT IS EXIST IN THE TREE then return true or false*/
bool toSearch(BinaryTreeNode *root, int val)
{
    if (root == NULL)
        return false;
    if (root->data == val)
    {
        return true;
    }

    if (val > root->data)
    {
        return toSearch(root->right, val);
    }
    else
    {
        return toSearch(root->left, val);
    }
}

/*THIS IS THE FUNCTION THAT RETURN THE MIN NODE OF THE BSTREE */
BinaryTreeNode *minNode(BinaryTreeNode *root)
{
    while (root && root->left)
    {
        root = root->left;
    }
    return root;
}

/*FUNCTION THAT TAKE NUM AS PARAM AND DELETE IF IF IT EXIST and return the root of the tree*/
BinaryTreeNode *deleteNode(BinaryTreeNode *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else
    {
        // case 1(if node is a leaf node )
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // case 2(if node has only left child)
        if (root->left == NULL)
        {
            BinaryTreeNode *temp = root->right;
            delete root;
            return temp;
        }

        // case 2(if node has only right child)
        if (root->right == NULL)
        {
            BinaryTreeNode *temp = root->left;
            delete root;
            return temp;
        }

        // case 3 (if the node has left or right both childs)
        BinaryTreeNode *minNodeOfRightSubTree = minNode(root->right); // ya to right wali tree ki min node lelo ya to left waly tree mein sy max node lelo
        
        root->data = minNodeOfRightSubTree->data; // jo node delete krni thi usko override krdia right subtree ki minimum node sy
        root->right = deleteNode(root->right,minNodeOfRightSubTree->data); // or minimum node ko delete krdia 
    }
    return root;
}

/*IN ORDER TREE TRAVERSAL */
void inOrder(BinaryTreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << "   ";
    inOrder(root->right);
}

int main()
{
    vector<int> v1 = {6, 3, 11, 5, 7, 18, 12, 2};
    BinaryTreeNode *rootOfBST = buildBSTFromVector(v1);

    inOrder(rootOfBST);

    if (toSearch(rootOfBST, 99))
    {
        cout << endl;
        cout << "founded \n";
    }
    else
    {
        cout << endl;
        cout << "not founded \n";
    }

    inOrder(deleteNode(rootOfBST,6));
}