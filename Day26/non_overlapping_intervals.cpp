#include <iostream>
using namespace std;

// Using Greedy Approach

class Solution
{
public:
    int minRemoval(vector<vector<int>> &intervals)
    {
        // Greedy
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        int mini = 0;
        for (int i = 1; i < n; i++)
        {
            if (intervals[i - 1][1] > intervals[i][0])
            {
                intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]);
                mini++;
            }
        }

        return mini;
    }
};

int main()
{
    return 0;
}