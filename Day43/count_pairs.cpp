#include <iostream>
using namespace std;

class Solution
{
public:
    int countPairs(vector<int> &arr, int target)
    {
        // Code here
        unordered_map<int, int> freq;

        int count = 0;

        for (int num : arr)
        {
            int temp = target - num;
            if (freq.find(temp) != freq.end())
                count += freq[temp];

            freq[num]++;
        }

        return count;
    }
};

int main()
{
    return 0;
}