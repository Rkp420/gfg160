#include <iostream>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int ans = 1, currCount = 1;

        for (int i = 1; i < n; i++)
        {
            if (arr[i] == arr[i - 1])
                continue;

            if (arr[i] == arr[i - 1] + 1)
                currCount++;
            else
                currCount = 1;

            ans = max(ans, currCount);
        }

        return ans;
    }
};

class Solution
{
public:
    int longestConsecutive(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int ans = 1, currCount = 1;

        for (int i = 1; i < n; i++)
        {
            if (arr[i] == arr[i - 1])
                continue;

            if (arr[i] == arr[i - 1] + 1)
                currCount++;
            else
                currCount = 1;

            ans = max(ans, currCount);
        }

        return ans;
    }
};

int main()
{
    return 0;
}