#include <iostream>
#include <set>
using namespace std;

// Simple and BruteForce

class Solution
{
public:
    int distinctElementInRange(int i, int j, vector<int> &arr)
    {

        set<int> distinct;
        for (int low = i; low <= j; low++)
            distinct.insert(arr[low]);

        return distinct.size();
    }

    vector<int> countDistinct(vector<int> &arr, int k)
    {
        int n = arr.size();

        vector<int> ans;

        for (int j = k - 1; j < n; j++)
        {
            int count = distinctElementInRange(j - k + 1, j, arr);
            ans.push_back(count);
        }

        return ans;
    }
};

// 2nd BruteForce

class Solution
{
public:
    vector<int> countDistinct(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> ans;

        // first Pass
        for (int i = 0; i <= n - k; i++)
        {

            set<int> distinct;

            for (int j = i; j < i + k; j++)
            {
                distinct.insert(arr[j]);
            }

            ans.push_back(distinct.size());
        }

        return ans;
    }
};

// Optimised (Using Two Pointer)

class Solution
{
public:
    vector<int> countDistinct(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> ans;

        unordered_map<int, int> freq;

        // First Pass
        for (int i = 0; i < k; i++)
            freq[arr[i]]++;
        ans.push_back(freq.size());

        // Second Pass
        for (int i = k; i < n; i++)
        {
            freq[arr[i]]++;
            freq[arr[i - k]]--;

            if (freq[arr[i - k]] == 0)
                freq.erase(arr[i - k]);

            ans.push_back(freq.size());
        }

        return ans;
    }
};

int main()
{
    return 0;
}