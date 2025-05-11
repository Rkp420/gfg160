#include <iostream>
using namespace std;

// User function template for C++
class Solution
{
public:
    vector<int> sumClosest(vector<int> &arr, int target)
    {
        int n = arr.size();
        if (n < 2)
            return {};

        sort(arr.begin(), arr.end());

        int left = 0, right = n - 1;
        int min_diff = INT_MAX;
        int max_abs_diff = -1;
        vector<int> result;

        while (left < right)
        {
            int sum = arr[left] + arr[right];
            int diff = abs(sum - target);

            if (diff < min_diff || (diff == min_diff && abs(arr[left] - arr[right]) > max_abs_diff))
            {
                min_diff = diff;
                max_abs_diff = abs(arr[left] - arr[right]);
                result = {arr[left], arr[right]};
            }

            if (sum < target)
                left++;
            else
                right--;
        }

        return result;
    }
};

int main()
{
    return 0;
}