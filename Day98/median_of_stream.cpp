#include <iostream>
using namespace std;

class Solution
{
public:
    vector<double> getMedian(vector<int> &arr)
    {
        priority_queue<int> leftMaxHeap;
        priority_queue<int, vector<int>, greater<int>> rightMinHeap;

        vector<double> res;

        for (int i = 0; i < arr.size(); i++)
        {
            leftMaxHeap.push(arr[i]);

            int temp = leftMaxHeap.top();
            leftMaxHeap.pop();
            rightMinHeap.push(temp);

            if (rightMinHeap.size() > leftMaxHeap.size())
            {
                temp = rightMinHeap.top();
                rightMinHeap.pop();
                leftMaxHeap.push(temp);
            }

            double median;
            if (leftMaxHeap.size() != rightMinHeap.size())
            {
                median = leftMaxHeap.top();
            }
            else
                median = (double)(leftMaxHeap.top() + rightMinHeap.top()) / 2;

            res.push_back(median);
        }

        return res;
    }
};

int main()
{
    return 0;
}