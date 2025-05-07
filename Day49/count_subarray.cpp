#include <iostream>
using namespace std;

// User function Template for C++

class Solution
{
public:
    int countSubarrays(vector<int> &arr, int k)
    {
        unordered_map<int, int> prefixSumFreq;

        int count = 0, prefixSum = 0;

        prefixSumFreq[0] = 1;

        for (int num : arr)
        {
            prefixSum += num;

            if (prefixSumFreq.find(prefixSum - k) != prefixSumFreq.end())
            {
                count += prefixSumFreq[prefixSum - k];
            }

            prefixSumFreq[prefixSum]++;
        }

        return count;
    }
};


int main()
{
    return 0;
}