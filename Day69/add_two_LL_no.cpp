#include <iostream>
using namespace std;


struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *prev = NULL, *curr = head, *next;

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    Node *trimLeadingZeros(Node *head)
    {
        while (head->next && head->data == 0)
            head = head->next;

        return head;
    }

    Node *addTwoLists(Node *num1, Node *num2)
    {

        Node *res = NULL, *curr = NULL;
        int carry = 0;

        num1 = trimLeadingZeros(num1);
        num2 = trimLeadingZeros(num2);

        num1 = reverse(num1);
        num2 = reverse(num2);

        while (num1 != NULL || num2 != NULL || carry != 0)
        {
            int sum = carry;

            if (num1 != NULL)
            {
                sum += num1->data;
                num1 = num1->next;
            }

            if (num2 != NULL)
            {
                sum += num2->data;
                num2 = num2->next;
            }

            Node *newNode = new Node(sum % 10);

            carry = sum / 10;

            if (res == NULL)
            {
                res = newNode;
                curr = newNode;
            }
            else
            {
                curr->next = newNode;
                curr = curr->next;
            }
        }

        return reverse(res);
    }
};

int main()
{
    return 0;
}