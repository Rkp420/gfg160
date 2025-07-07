#include <iostream>
using namespace std;

class Solution
{
private:
    stack<int> mainSt;
    stack<int> minSt;

public:
    Solution()
    {
    }

    // Add an element to the top of Stack
    void push(int x)
    {
        mainSt.push(x);
        if (minSt.empty() || x <= minSt.top())
        {
            minSt.push(x);
        }
    }

    // Remove the top element from the Stack

    void pop()
    {
        if (!mainSt.empty())
        {
            if (mainSt.top() == minSt.top())
            {
                minSt.pop();
            }
            mainSt.pop();
        }
    }

    // Returns top element of the Stack
    int peek()
    {
        if (!mainSt.empty())
        {
            return mainSt.top();
        }
        return -1;
    }

    // Finds minimum element of Stack
    int getMin()
    {
        if (!minSt.empty())
        {
            return minSt.top();
        }

        return -1;
    }
};

int main()
{
    return 0;
}