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
};

class Solution
{
public:
    Node *findFirstNode(Node *head)
    {
        Node *slow = head;
        Node *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                Node *start = head;
                while (start != slow)
                {
                    start = start->next;
                    slow = slow->next;
                }

                return start;
            }
        }

        return NULL;
    }
};

int main()
{
    return 0;
}