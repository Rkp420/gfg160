#include <iostream>
using namespace std;

// BruteForce

class Solution
{

public:
    int maxWater(vector<int> &arr)
    {

        // BruteForrce
        int n = arr.size();
        int ans = 0;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int currContain = min(arr[i], arr[j]) * (j - i);
                ans = max(ans, currContain);
            }
        }

        return ans;
    }
};

// Using Two Pointer Approch

class Solution
{

public:
    int maxWater(vector<int> &arr)
    {

        // Using Two Pointer Approach
        int left = 0, right = arr.size() - 1;
        int ans = 0;

        while (left < right)
        {

            int currContainedWater = min(arr[left], arr[right]) * (right - left);
            ans = max(ans, currContainedWater);

            // Case 1 : leftHeight < rightHeight
            if (arr[left] < arr[right])
                left++;

            // Case 2 : rightHeight <= leftHeight
            else
                right--;
        }

        return ans;
    }
};

int main()
{
    return 0;
}