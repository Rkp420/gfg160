#include <iostream>
using namespace std;

// BruteForce

class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        // BruteForce
        int n = arr.size();

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += arr[j];
                if (sum == k)
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};

// Using Prefix Sum

class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        // BruteForce
        int n = arr.size();

        unordered_map<int, int> mp;

        int res = 0;
        int prefixSum = 0;
        for (int i = 0; i < n; i++)
        {
            prefixSum += arr[i];

            // Case 1 : prefix Sum == k
            if (prefixSum == k)
                res = i + 1;

            // Case 2 : if PrefixSum - k
            else if (mp.find(prefixSum - k) != mp.end())
            {
                res = max(res, i - mp[prefixSum - k]);
            }

            // Case 3 : we have to Store this prefixSum
            if (mp.find(prefixSum) == mp.end())
            {
                mp[prefixSum] = i;
            }
        }

        return res;
    }
};

int main()
{
    return 0;
}