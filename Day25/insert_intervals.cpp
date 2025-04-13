#include <iostream>
using namespace std;

// Insert New Interval and Apply the Merge Intervals Concept 
// Time-Complexity : O(nlogn) + O(n);
class Solution
{
public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval)
    {
        // code here
        // Step 1 : Push this New Interval into Intervals
        intervals.push_back(newInterval);

        // Step 2 : Apply the Same Approach as Merge Intervals
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {
            vector<int> &last = res.back();
            vector<int> &curr = intervals[i];

            if (last[1] >= curr[0])
                last[1] = max(last[1], curr[1]);
            else
                res.push_back(curr);
        }

        return res;
    }
};

// Using One Pass Because it Already Sorted

// User function Template for C++

class Solution
{
public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval)
    {
        vector<vector<int>> res;
        int i = 0;
        int n = intervals.size();

        while (i < n && intervals[i][1] < newInterval[0])
        {
            res.push_back(intervals[i]);
            i++;
        }

        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        res.push_back(newInterval);

        while (i < n)
        {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};

int main()
{
    return 0;
}