#include <iostream>
using namespace std;

class Solution
{
public:
    long subarrayXor(vector<int> &arr, int k)
    {

        unordered_map<long, long> freq;

        long count = 0;
        long prefixXor = 0;

        for (int num : arr)
        {
            prefixXor ^= num;

            if (prefixXor == k)
                count++;

            long req = prefixXor ^ k;
            if (freq.find(req) != freq.end())
            {
                count += freq[req];
            }

            freq[prefixXor]++;
        }

        return count;
    }
};

int main()
{
    return 0;
}