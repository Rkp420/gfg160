#include <iostream>
using namespace std;

// BruteForce

class Solution
{
public:
    int countFreq(vector<int> &arr, int target)
    {
        // BruteForce
        int lb = -1, ub = -1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (lb == -1 && arr[i] == target)
                lb = i;
            if (arr[i] == target)
                ub = i;
        }

        return (lb == -1) ? 0 : (ub - lb + 1);
    }
};

// Using Binary Search
class Solution
{
public:
    int lbound(vector<int> &arr, int k)
    {
        int i = 0, j = arr.size() - 1;

        int ans = -1;
        while (i <= j)
        {
            int mid = (i + (j - i) / 2);

            if (arr[mid] == k)
            {
                ans = mid;
                j = mid - 1;
            }
            else if (arr[mid] > k)
            {
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }

        return ans;
    }
    int ubound(vector<int> &arr, int k)
    {
        int i = 0, j = arr.size() - 1;

        int ans = -1;
        while (i <= j)
        {
            int mid = (i + (j - i) / 2);

            if (arr[mid] == k)
            {
                ans = mid;
                i = mid + 1;
            }
            else if (arr[mid] > k)
            {
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }

        return ans;
    }
    int countFreq(vector<int> &arr, int target)
    {
        // Using Binary Search
        int lb = lbound(arr, target);
        int ub = ubound(arr, target);
        return (lb == -1 || ub == -1) ? 0 : ub - lb + 1;
    }
};

// Using Stl
class Solution
{
public:
    int countFreq(vector<int> &arr, int target)
    {
        // Using Stl
        int lower = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
        int upper = upper_bound(arr.begin(), arr.end(), target) - arr.begin();

        return (lower == arr.size() || arr[lower] != target) ? 0 : upper - lower;
    }
};

int main()
{
    return 0;
}