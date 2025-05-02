#include <iostream>
#include <set>
using namespace std;

// BruteForce

class Solution
{
public:
    vector<vector<int>> findTriplets(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> res;

        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (arr[i] + arr[j] + arr[k] == 0)
                    {
                        res.push_back({i, j, k});
                    }
                }
            }
        }

        return res;
    }
};

// Using Unoredered_map

class Solution
{
public:
    vector<vector<int>> findTriplets(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> res;

        for (int i = 0; i < n - 2; i++)
        {
            unordered_map<int, int> mp; // Value -> index

            for (int j = i + 1; j < n; j++)
            {
                int target = -arr[i] - arr[j];

                if (mp.find(target) != mp.end())
                {
                    int k = j;
                    int prev = mp[target];

                    vector<int> triplet = {mp[target], i, j};
                    sort(triplet.begin(), triplet.end());

                    if (res.empty() || res.back() != triplet)
                        res.push_back(triplet);
                }

                mp[arr[j]] = j;
            }
        }

        return res;
    }
};

class Solution
{
public:
    vector<vector<int>> findTriplets(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> res;

        for (int i = 0; i < n - 2; i++)
        {
            unordered_map<int, int> mp; // Value -> index

            for (int j = i + 1; j < n; j++)
            {
                int target = -arr[i] - arr[j];

                if (mp.find(target) != mp.end())
                {
                    int k = j;
                    int prev = mp[target];

                    vector<int> triplet = {mp[target], i, j};
                    sort(triplet.begin(), triplet.end());

                    if (res.empty() || res.back() != triplet)
                        res.push_back(triplet);
                }

                mp[arr[j]] = j;
            }
        }

        return res;
    }
};

class Solution
{
public:
    vector<vector<int>> findTriplets(vector<int> &arr)
    {
        int n = arr.size();
        set<vector<int>> uniqueTriplets;

        for (int i = 0; i < n - 2; i++)
        {
            unordered_map<int, vector<int>> mp; // Value -> index

            for (int j = i + 1; j < n; j++)
            {
                int target = -arr[i] - arr[j];

                if (mp.find(target) != mp.end())
                {
                    for (int idx : mp[target])
                    {

                        vector<int> triplet = {idx, i, j};
                        sort(triplet.begin(), triplet.end());
                        uniqueTriplets.insert(triplet);
                    }
                }

                mp[arr[j]].push_back(j);
            }
        }

        vector<vector<int>> result(uniqueTriplets.begin(), uniqueTriplets.end());
        return result;
    }
};

int main()
{
    return 0;
}