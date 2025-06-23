#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> kLargest(vector<int> &arr, int k)
    {

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : arr)
        {
            minHeap.push(num);
            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }

        vector<int> result;
        while (!minHeap.empty())
        {
            result.push_back(minHeap.top());
            minHeap.pop();
        }

        sort(result.rbegin(), result.rend());
        return result;
    }
};

int main()
{
    return 0;
}