#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor to initialize a new node
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
class Solution
{
public:
    const int MARKER = -1;

    vector<int> serialize(Node *root)
    {
        vector<int> result;
        serializeHelper(root, result);
        return result;
    }

    void serializeHelper(Node *root, vector<int> &result)
    {
        if (!root)
        {
            result.push_back(MARKER);
            return;
        }

        result.push_back(root->data);
        serializeHelper(root->left, result);
        serializeHelper(root->right, result);
    }

    Node *deSerialize(vector<int> &arr)
    {
        int index = 0;
        return deSerializeHelper(arr, index);
    }

    Node *deSerializeHelper(vector<int> &arr, int &index)
    {
        if (index >= arr.size() || arr[index] == MARKER)
        {
            index++;
            return NULL;
        }

        Node *root = new Node(arr[index++]);
        root->left = deSerializeHelper(arr, index);
        root->right = deSerializeHelper(arr, index);
        return root;
    }
};

int main()
{
    return 0;
}