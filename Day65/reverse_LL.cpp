#include <iostream>
using namespace std;


struct Node
{
    int data;
    struct Node *next;
};


class Solution
{
public:
    Node *reverseList(struct Node *head)
    {

        Node *prev = NULL;
        Node *curr = head;

        while (curr)
        {
            Node *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
};

int main()
{
    return 0;
}