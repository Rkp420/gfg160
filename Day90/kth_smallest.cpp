#include <iostream>
using namespace std;



struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    int count = 0;
    int ans = -1;

    void inOrder(Node *root, int k)
    {
        if (!root)
            return;

        inOrder(root->left, k);

        count++;
        if (count == k)
        {
            ans = root->data;
            return;
        }

        inOrder(root->right, k);
    }

    int kthSmallest(Node *root, int k)
    {
        count = 0;
        ans = -1;
        inOrder(root, k);
        return ans;
    }
};

int main()
{
    return 0;
}