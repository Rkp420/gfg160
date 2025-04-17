#include <iostream>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &arr)
    {

        // Using Binary Search
        int low = 0, high = arr.size() - 1;

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] > arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }

        return arr[low];
    }
};

class Solution
{
public:
    int findMin(vector<int> &arr)
    {
        // Using Linear Search
        int ans = INT_MAX;
        for (int &num : arr)
            ans = min(ans, num);

        return ans;
    }
};

class Solution
{
public:
    int findMin(vector<int> &arr)
    {
        // Using Stl
        int mini = *min_element(arr.begin(), arr.end());
        return mini;
    }
};

int main()
{
    return 0;
}