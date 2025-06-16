#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    bool validate(Node *node, long long minVal, long long maxVal)
    {
        if (!node)
            return true;

        if (node->data <= minVal || node->data >= maxVal)
            return false;

        return validate(node->left, minVal, node->data) &&
               validate(node->right, node->data, maxVal);
    }

    bool isBST(Node *root)
    {

        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};

int main()
{
    return 0;
}