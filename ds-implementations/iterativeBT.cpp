#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode
{
private:
    int val;

public:
    TreeNode *right = nullptr;
    TreeNode *left = nullptr;

    TreeNode(int val)
    {
        this->val = val;
    }

    TreeNode(int val, TreeNode *right, TreeNode *left)
    {
        this->val = val;
        this->right = right;
        this->left = left;
    }

    int getVal()
    {
        return val;
    }
};

void addLeftmost(TreeNode *root, stack<TreeNode *> &toVisit)
{
    while (root)
    {
        toVisit.push(root);
        root = root->left;
    }
    return;
}

void traverseInOrder(TreeNode *root)
{
    stack<TreeNode *> toVisit;
    addLeftmost(root, toVisit);
    while (!toVisit.empty())
    {
        TreeNode *curr = toVisit.top();
        toVisit.pop();
        cout << curr->getVal() << endl;

        if (curr->right)
        {
            addLeftmost(curr->right, toVisit);
        }
    }
    return;
}

TreeNode *insert(TreeNode *root, int valToInsert)
{
    if (!root)
        return new TreeNode(valToInsert);
    if (root->getVal() <= valToInsert)
    {
        root->right = insert(root->right, valToInsert);
    }
    else
    {
        root->left = insert(root->left, valToInsert);
    }

    return root;
}

void traversePreOrder (TreeNode * root) {
    stack<TreeNode *> toVisit; 
    toVisit.push(root);
    while(!toVisit.empty()) {
        TreeNode * curr = toVisit.top();
        toVisit.pop(); 
        cout << curr -> getVal() << endl;
        if (curr -> right) 
            toVisit.push(curr -> right);
        if (curr -> left)
            toVisit.push(curr -> left);
    }
    return;
}

int main()
{
    TreeNode *root = new TreeNode(10);
    vector<int> valsToInsert = {9, 8, 5, 12, 14, 19, 4, 3, 6};
    for (int valToInsert : valsToInsert)
    {
        insert(root, valToInsert);
    }
    cout << "In order traversal:" << endl;
    traverseInOrder(root);

    cout << "Pre order traversal:" << endl;
    traversePreOrder(root);

    return 0;
}
