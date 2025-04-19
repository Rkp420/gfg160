#include <iostream>
using namespace std;

class Solution
{
public:
    int peakElement(vector<int> &arr)
    {
        // Using Linear Search
        int n = arr.size();

        if (n == 1)
            return 0;

        if (arr[0] > arr[1])
            return 0;
        if (arr[n - 1] > arr[n - 2])
            return n - 1;

        int low = 1, high = n - 2;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                return mid;

            if (arr[mid + 1] > arr[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }

        return 0;
    }
};

class Solution
{
public:
    int peakElement(vector<int> &arr)
    {
        // Using Linear Search
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            bool left = true;
            bool right = true;

            if (i > 0 && arr[i] <= arr[i - 1])
                left = false;
            if (i < n - 1 && arr[i] <= arr[i + 1])
                right = false;

            if (left && right)
                return i;
        }

        return 0;
    }
};

int main()
{
    return 0;
}