#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }

} *head;

class Solution
{
public:
    Node *reverseKGroup(Node *head, int k)
    {
        if (!head || k == 1)
            return head;

        deque<Node *> dq;
        Node *curr = head;

        while (curr)
        {
            int count = 0;

            while (curr && count < k)
            {
                dq.push_back(curr);
                curr = curr->next;
                count++;
            }

            while (!dq.empty())
            {
                Node *front = dq.front();
                Node *last = dq.back();
                swap(front->data, last->data);

                if (!dq.empty())
                {
                    dq.pop_front();
                }

                if (!dq.empty())
                {
                    dq.pop_back();
                }
            }
        }
        return head;
    }
};

int main()
{
    return 0;
}
