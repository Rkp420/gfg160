#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution
{
public:
    Node *rotate(Node *head, int k)
    {

        if (!head || k == 0)
            return head;

        // Step 1: Count length and get last node
        Node *temp = head;
        int n = 1;
        while (temp->next)
        {
            temp = temp->next;
            n++;
        }

        // Step 2: Adjust k to within bounds
        k = k % n;
        if (k == 0)
            return head;

        Node *curr = head;
        for (int i = 1; i < k; i++)
        {
            curr = curr->next;
        }

        // Step 4: new haed is next node, break and reconnect
        Node *newHead = curr->next;
        curr->next = NULL;
        temp->next = head;

        return newHead;
    }
};

int main()
{
    return 0;
}