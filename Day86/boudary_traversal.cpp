#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution
{
public:
    bool isLeaf(Node *node)
    {
        return !node->left && !node->right;
    }

    void addLeftBoundary(Node *node, vector<int> &res)
    {
        Node *curr = node->left;
        while (curr)
        {
            if (!isLeaf(curr))
                res.push_back(curr->data);
            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    void addRightBoundary(Node *node, vector<int> &res)
    {
        Node *curr = node->right;
        vector<int> temp;
        while (curr)
        {
            if (!isLeaf(curr))
                temp.push_back(curr->data);
            if (curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }

        reverse(temp.begin(), temp.end());
        res.insert(res.end(), temp.begin(), temp.end());
    }

    void addLeaves(Node *node, vector<int> &res)
    {
        if (isLeaf(node))
        {
            res.push_back(node->data);
            return;
        }

        if (node->left)
            addLeaves(node->left, res);
        if (node->right)
            addLeaves(node->right, res);
    }

    vector<int> boundaryTraversal(Node *root)
    {
        vector<int> res;
        if (!root)
            return res;

        if (!isLeaf(root))
            res.push_back(root->data);

        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);

        return res;
    }
};

int main()
{
    return 0;
}