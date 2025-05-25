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

// Recursive approach
class Solution
{
public:
    Node *sortedMerge(Node *head1, Node *head2)
    {

        if (!head1)
            return head2;
        if (!head2)
            return head1;

        if (head1->data <= head2->data)
        {
            head1->next = sortedMerge(head1->next, head2);
            return head1;
        }
        else
        {
            head2->next = sortedMerge(head1, head2->next);
            return head2;
        }
    }
};

// Iterative Solution
class Solution
{
public:
    Node *sortedMerge(Node *head1, Node *head2)
    {

        Node *dummy = new Node(0);
        Node *tail = dummy;

        while (head1 && head2)
        {
            if (head1->data <= head2->data)
            {
                tail->next = head1;
                head1 = head1->next;
            }
            else
            {
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next;
        }

        if (head1)
            tail->next = head1;
        if (head2)
            tail->next = head2;

        Node *result = dummy->next;
        delete dummy;
        return result;
    }
};

int main()
{
    return 0;
}