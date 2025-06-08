#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {

        if (!root)
            return {};

        vector<vector<int>> ans;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int currSize = q.size();

            vector<int> temp;
            while (currSize--)
            {
                Node *node = q.front();
                q.pop();

                temp.push_back(node->data);
                Node *left = node->left;
                Node *right = node->right;

                if (left)
                    q.push(left);
                if (right)
                    q.push(right);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};

int main()
{
    return 0;
}