#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    int dfs(Node *node)
    {
        if (!node->left && !node->right)
            return 0;

        int leftHeight = INT_MIN;
        if (node->left)
            leftHeight = 1 + dfs(node->left);
        int rightHeight = INT_MIN;
        if (node->right)
            rightHeight = 1 + dfs(node->right);

        return max(leftHeight, rightHeight);
    }

    int height(Node *node)
    {
        return dfs(node);
    }
};

class Solution
{
public:
    int dfs(Node *node)
    {
        if (!node)
            return -1;

        int leftHeight = dfs(node->left);
        int rightHeight = dfs(node->right);

        return 1 + max(leftHeight, rightHeight);
    }

    int height(Node *node)
    {
        return dfs(node);
    }
};

int main()
{
    return 0;
}