#include <iostream>
using namespace std;


struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};

class Solution
{
public:
    struct compare
    {
        bool operator()(Node *a, Node *b)
        {
            return a->data > b->data;
        }
    };
    Node *mergeKLists(vector<Node *> &arr)
    {
        priority_queue<Node *, vector<Node *>, compare> minHeap;

        for (Node *listHead : arr)
        {
            if (listHead != NULL)
                minHeap.push(listHead);
        }

        Node *dummy = new Node(0);
        Node *tail = dummy;

        while (!minHeap.empty())
        {
            Node *smallest = minHeap.top();
            minHeap.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next != NULL)
                minHeap.push(smallest->next);
        }

        return dummy->next;
    }
};

int main()
{
    return 0;
}