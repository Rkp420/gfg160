#include <iostream>
using namespace std;



class Node {
public:
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
    int maxSum;
    int solve(Node *root)
    {
        if (!root)
            return 0;

        int left = max(0, solve(root->left));
        int right = max(0, solve(root->right));

        int currSum = root->data + left + right;

        maxSum = max(maxSum, currSum);

        return root->data + max(left, right);
    }

    int findMaxSum(Node *root)
    {
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
    }
};

int main()
{
    return 0;
}