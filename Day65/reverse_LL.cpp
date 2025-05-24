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

// Recursive Appproach
class Sol
{
public:
    Node *reverseListRecursive(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head; // Base case: empty list or last node

        Node *newHead = reverseListRecursive(head->next); // Reverse rest of the list
        head->next->next = head;                          // Make the next node point to current
        head->next = NULL;                                // Cut the original link

        return newHead; // New head is the last node
    }

    Node *reverseList(struct Node *head)
    {
        return reverseListRecursive(head);
    }
};

int main()
{
    return 0;
}