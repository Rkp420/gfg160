#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}


class Solution
{
public:
    int maxDiameter = 0;
    int dfs(Node *node)
    {
        if (!node)
            return 0;

        int leftHeight = dfs(node->left);
        int rightHeight = dfs(node->right);

        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }

    int diameter(Node *root)
    {
        dfs(root);
        return maxDiameter;
    }
};

int main()
{
    return 0;
}