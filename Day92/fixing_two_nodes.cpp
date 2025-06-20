#include <iostream>
using namespace std;


class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};


class Solution
{
public:
    Node *first, *middle, *last, *prev;
    void correctBstHelper(Node *root)
    {
        if (!root)
            return;

        correctBstHelper(root->left);

        if (prev && root->data < prev->data)
        {
            if (!first)
            {
                first = prev;
                middle = root;
            }
            else
                last = root;
        }

        prev = root;

        correctBstHelper(root->right);
    }

    void correctBST(Node *root)
    {
        first = middle = last = prev = NULL;

        correctBstHelper(root);

        if (first && last)
        {
            swap(first->data, last->data);
        }
        else if (first && middle)
        {
            swap(first->data, middle->data);
        }
    }
};

int main()
{
    return 0;
}