#include <iostream>
using namespace std;

class Solution
{
public:
    int getMinDiff(vector<int> &arr, int k)
    {
        // code here
        int n = arr.size();

        if (n == 1)
            return 0;

        sort(arr.begin(), arr.end());

        int ans = arr[n - 1] - arr[0];

        int largest = arr[n - 1] - k;
        int smallest = arr[0] + k;

        for (int i = 0; i < n - 1; i++)
        {
            int localMin = min(smallest, arr[i + 1] - k);
            int localMax = max(largest, arr[i] + k);

            if (localMin < 0)
                continue;

            ans = min(ans, localMax - localMin);
        }

        return ans;
    }
};

int main()
{
    return 0;
}