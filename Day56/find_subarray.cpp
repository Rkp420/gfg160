#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> subarraySum(vector<int> &arr, int target)
    {
        int start = 0, sum = 0;
        for (int end = 0; end < arr.size(); end++)
        {
            sum += arr[end];

            while (sum > target && start < end)
            {
                sum -= arr[start];
                start++;
            }

            if (sum == target)
            {
                return {start + 1, end + 1};
            }
        }

        return {-1};
    }
};

int main()
{
    return 0;
}