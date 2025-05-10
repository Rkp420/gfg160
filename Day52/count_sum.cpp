#include <iostream>
using namespace std;

int countPairs(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    int left = 0, right = arr.size() - 1;
    int count = 0;

    while (left < right)
    {
        if (arr[left] + arr[right] < target)
        {
            count += (right - left);
            left++;
        }
        else
        {
            right--;
        }
    }

    return count;
}

int main()
{
    return 0;
}