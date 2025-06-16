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
    int dfs(Node *root, int currSum, int k, unordered_map<int, int> &prefix)
    {
        if (!root)
            return 0;

        currSum += root->data;
        int count = 0;
        if (prefix.find(currSum - k) != prefix.end())
        {
            count += prefix[currSum - k];
        }

        prefix[currSum]++;

        count += dfs(root->left, currSum, k, prefix);
        count += dfs(root->right, currSum, k, prefix);

        prefix[currSum]--;

        return count;
    }

    int sumK(Node *root, int k)
    {

        unordered_map<int, int> prefix;
        prefix[0] = 1;
        return dfs(root, 0, k, prefix);
    }
};

int main()
{
    return 0;
}