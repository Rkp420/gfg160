#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPossible(int mid, vector<int> &arr, int k)
    {
        int students = 1;
        int currPages = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > mid)
                return false;

            if ((currPages + arr[i]) <= mid)
                currPages += arr[i];
            else
            {
                students++;
                currPages = arr[i];
                if (students > k)
                    return false;
            }
        }

        return true;
    }
    int findPages(vector<int> &arr, int k)
    {
        if (arr.size() < k)
            return -1;

        int totalPages = 0;
        for (int page : arr)
            totalPages += page;

        int minPages = *max_element(arr.begin(), arr.end());
        int maxPages = totalPages;

        int ans = -1;
        while (minPages <= maxPages)
        {
            int mid = minPages + (maxPages - minPages) / 2;

            if (isPossible(mid, arr, k))
            {
                ans = mid;
                maxPages = mid - 1;
            }
            else
            {
                minPages = mid + 1;
            }
        }

        return ans;
    }
};

int main()
{
    return 0;
}