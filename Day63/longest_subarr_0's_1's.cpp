#include <iostream>
using namespace std;

class Solution
{
public:
    int maxLen(vector<int> &arr)
    {
        // Your code here
        unordered_map<int, int> prefixSumIdx;
        int maxLen = 0;
        int sum = 0;

        prefixSumIdx[0] = -1;

        for (int i = 0; i < arr.size(); i++)
        {
            sum += (arr[i] == 0) ? -1 : 1;

            if (prefixSumIdx.find(sum) != prefixSumIdx.end())
            {
                int len = i - prefixSumIdx[sum];
                maxLen = max(maxLen, len);
            }
            else
            {
                prefixSumIdx[sum] = i;
            }
        }

        return maxLen;
    }
};

int main()
{
    return 0;
}