#include <iostream>
#include <unordered_set>
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
    unordered_set<int> seen;

    bool dfs(Node *root, int target)
    {
        if (!root)
            return false;

        if (seen.count(target - root->data))
            return true;
        seen.insert(root->data);

        return dfs(root->left, target) || dfs(root->right, target);
    }

    bool findTarget(Node *root, int target)
    {
        seen.clear();
        return dfs(root, target);
    }
};

int main()
{
    return 0;
}