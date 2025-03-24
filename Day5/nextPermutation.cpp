#include <iostream>
using namespace std;

class Solution
{
public:
    int findIdxOfSmallestGreater(vector<int> &arr, int i, int j, int target)
    {
        int ans = -1;
        while (i <= j)
        {
            if (arr[i] > target)
            {
                ans = i;
            }
            else
            {
                break;
            }
            i++;
        }

        return ans;
    }
    void nextPermutation(vector<int> &arr)
    {

        // Step 1 : Find Critical Point
        int n = arr.size();
        if (n == 1)
            return;

        int criticalIdx = n - 2;

        while (criticalIdx >= 0)
        {
            if (arr[criticalIdx] < arr[criticalIdx + 1])
                break;
            else
                criticalIdx--;
        }

        if (criticalIdx < 0)
        {
            reverse(arr.begin(), arr.end());
            return;
        }

        int swapIdx = findIdxOfSmallestGreater(arr, criticalIdx + 1, n - 1, arr[criticalIdx]);

        if (swapIdx == -1)
            return;

        swap(arr[criticalIdx], arr[swapIdx]);

        reverse(arr.begin() + criticalIdx + 1, arr.end());

        return;
    }
};

//{ Driver Code Starts.
int main()
{
    return 0;
}
