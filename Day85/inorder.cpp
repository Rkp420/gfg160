#include <iostream>
#include <vector>
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
    void solve(Node *node, vector<int> &ans)
    {
        if (node == NULL)
            return;

        solve(node->left, ans);
        ans.push_back(node->data);
        solve(node->right, ans);
    }

    vector<int> inOrder(Node *root)
    {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};

int main()
{
    return 0;
}