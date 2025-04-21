#include <iostream>
using namespace std;

// Using binary Search

// User function Template for C++

class Solution
{
public:
    bool isPossible(vector<int> &stalls, int dis, int k)
    {
        int count = 1;
        int lastPos = stalls[0];

        for (int i = 1; i < stalls.size(); i++)
        {
            if (stalls[i] - lastPos >= dis)
            {
                count++;
                lastPos = stalls[i];
            }

            if (count >= k)
                return true;
        }

        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k)
    {

        sort(stalls.begin(), stalls.end());

        int low = 0;
        int high = stalls.back() - stalls.front();
        int ans = 0;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (isPossible(stalls, mid, k))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main()
{
    return 0;
}