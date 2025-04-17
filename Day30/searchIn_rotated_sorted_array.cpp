#include <iostream>
using namespace std;

class Solution
{
public:
    int search(vector<int> &arr, int key)
    {

        // Using PreDefined Function
        auto it = find(arr.begin(), arr.end(), key);

        if (it != arr.end())
            return it - arr.begin();
        else
            return -1;
    }
};

class Solution
{
public:
    int search(vector<int> &arr, int key)
    {

        // Using Binary Search For Sorted Array
        int low = 0, high = arr.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] == key)
                return mid;

            // if We are on the left
            if (arr[mid] >= arr[low])
            {
                if (arr[low] <= key && key < arr[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (arr[mid] < key && key <= arr[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};

class Solution
{
public:
    int search(vector<int> &arr, int key)
    {

        // Extreme Naive Approach : Linear Search
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == key)
                return i;
        }

        return -1;
    }
};

int main()
{
    return 0;
}