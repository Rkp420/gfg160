#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    int preIdx = 0;
    unordered_map<int, int> inorderMap;

    Node *solve(int inStart, int inEnd, vector<int> &inorder, vector<int> &preorder)
    {
        if (inStart > inEnd)
            return NULL;

        int curr = preorder[preIdx++];
        Node *node = new Node(curr);

        if (inStart == inEnd)
            return node;

        int inIdx = inorderMap[curr];

        node->left = solve(inStart, inIdx - 1, inorder, preorder);
        node->right = solve(inIdx + 1, inEnd, inorder, preorder);

        return node;
    }

    Node *buildTree(vector<int> &inorder, vector<int> &preorder)
    {
        preIdx = 0;
        inorderMap.clear();

        for (int i = 0; i < inorder.size(); i++)
        {
            inorderMap[inorder[i]] = i;
        }

        return solve(0, inorder.size() - 1, inorder, preorder);
    }
};

int main()
{
    return 0;
}