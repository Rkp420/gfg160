#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};


    class Solution
{
public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node *node)
    {

        if (!node)
            return;

        mirror(node->left);
        mirror(node->right);

        Node *temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
};

int main()
{
    return 0;
}