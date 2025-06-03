#include <iostream>
using namespace std;

class LRUCache
{
private:
    struct Node
    {
        int key, value;
        Node *prev;
        Node *next;

        Node(int k, int v) : key(k), value(v), prev(NULL), next(NULL) {}
    };

    unordered_map<int, Node *> cache;
    int capacity;
    Node *head;
    Node *tail;

    void remove(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtFront(Node *node)
    {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int cap)
    {
        capacity = cap;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (cache.find(key) != cache.end())
        {
            Node *node = cache[key];
            remove(node);
            insertAtFront(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            Node *node = cache[key];
            node->value = value;
            remove(node);
            insertAtFront(node);
        }
        else
        {
            if (cache.size() == capacity)
            {
                Node *lru = tail->prev;
                remove(lru);
                cache.erase(lru->key);
                delete lru;
            }

            Node *newNode = new Node(key, value);
            insertAtFront(newNode);
            cache[key] = newNode;
        }
    }
};

int main()
{
    return 0;
}