#include <iostream>
using namespace std;

// First Approach : Using HashMap
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *cloneLinkedList(Node *head)
    {

        if (!head)
            return head;

        // Storing Copy of Each Node
        unordered_map<Node *, Node *> copyNodeMap;
        Node *temp = head;
        while (temp)
        {
            Node *newNode = new Node(temp->data);
            copyNodeMap[temp] = newNode;
            temp = temp->next;
        }

        // Now all the Nodes have been created
        // Start copying the Nodes
        temp = head;
        Node *dummy = new Node(-1);
        Node *res = dummy;
        while (temp)
        {
            Node *copyNode = copyNodeMap[temp];
            copyNode->next = copyNodeMap[temp->next];
            copyNode->random = copyNodeMap[temp->random];

            res->next = copyNode;
            res = res->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};

// 2nd Approach
/* Link list Node
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};*/

class Solution
{
public:
    Node *cloneLinkedList(Node *head)
    {

        if (!head)
            return head;

        // Inserting CopyNode in Beetween Nodes
        Node *temp = head;
        while (temp)
        {
            Node *newNode = new Node(temp->data);
            newNode->next = temp->next;
            temp->next = newNode;

            temp = temp->next->next;
        }

        // Now Assign the random Nodes
        temp = head;
        while (temp)
        {
            if (temp->random)
                temp->next->random = temp->random->next;

            temp = temp->next->next;
        }

        temp = head;
        Node *dummy = new Node(-1);
        Node *res = dummy;
        while (temp)
        {
            res->next = temp->next;
            res = res->next;

            temp->next = res->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};

int main()
{
    return 0;
}