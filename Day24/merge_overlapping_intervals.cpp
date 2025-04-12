#include <iostream>
using namespace std;


class Solution
{
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>> &arr)
    {
        // Most Optimal
        int n = arr.size();

        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        res.push_back(arr[0]);

        for (int i = 1; i < n; i++)
        {
            vector<int> &last = res.back();
            vector<int> &curr = arr[i];

            if (last[1] >= curr[0])
            {
                last[1] = max(last[1], curr[1]);
            }
            else
            {
                res.push_back(curr);
            }
        }

        return res;
    }
};


int main()
{
    return 0;
}