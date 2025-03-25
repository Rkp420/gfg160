#include <iostream>
using namespace std;

// Naive Approach

class Solution
{
public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int> &arr)
    {
        // Your code goes here.
        int n = arr.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = i; j < n; j++)
            {
                if (arr[i] == arr[j])
                    count++;
            }
            if (count > n / 3)
            {
                if (ans.size() == 0 || ans[0] != arr[i])
                    ans.push_back(arr[i]);
            }

            if (ans.size() == 2)
                break;
        }
        if (ans.size() == 2 && ans[0] > ans[1])
            swap(ans[0], ans[1]);
        return ans;
    }
};


// Using HashMap

class Solution
{
public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int> &arr)
    {
        // Your code goes here.
        int n = arr.size();
        vector<int> ans;

        unordered_map<int, int> m;

        for (int num : arr)
            m[num]++;

        for (auto it : m)
        {
            if (it.second > n / 3)
            {
                if (ans.size() == 0 || ans[0] != it.first)
                {
                    ans.push_back(it.first);
                }
            }
            if (ans.size() == 2)
                break;
        }

        if (ans.size() == 2 && ans[0] > ans[1])
            swap(ans[0], ans[1]);

        return ans;
    }
};

// Boyer's Voting Algorithm

class Solution
{
public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int> &arr)
    {
        // Your code goes here.
        int n = arr.size();
        vector<int> ans;

        int cand1 = -1, cand2 = -1, count1 = 0, count2 = 0;
        // First Pass
        for (int num : arr)
        {
            if (num == cand1)
                count1++;
            else if (num == cand2)
                count2++;
            else if (count1 == 0)
            {
                cand1 = num;
                count1 = 1;
            }
            else if (count2 == 0)
            {
                cand2 = num;
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        // Second Pass
        count1 = count2 = 0;
        for (int num : arr)
        {
            if (num == cand1)
                count1++;
            else if (num == cand2)
                count2++;
        }
        if (count1 > n / 3)
            ans.push_back(cand1);
        if (count2 > n / 3 && cand1 != cand2)
            ans.push_back(cand2);

        if (ans.size() == 2 && ans[0] > ans[1])
            swap(ans[0], ans[1]);
        return ans;
    }
};

int main()
{
    return 0;
}