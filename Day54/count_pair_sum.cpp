#include <iostream>
using namespace std;

class Solution
{
public:
    int countPairs(vector<int> &arr, int target)
    {
        int n = arr.size();
        int left = 0, right = n - 1;
        long long count = 0;

        while (left < right)
        {
            int sum = arr[left] + arr[right];

            if (sum < target)
            {
                left++;
            }
            else if (sum > target)
            {
                right--;
            }
            else
            {
                if (arr[left] == arr[right])
                {
                    long long k = right - left + 1;
                    count += (k * (k - 1)) / 2;
                    break;
                }
                else
                {
                    int cntL = 1, cntR = 1;

                    while (left + 1 < right && arr[left] == arr[left + 1])
                    {
                        cntL++;
                        left++;
                    }
                    while (right - 1 > left && arr[right] == arr[right - 1])
                    {
                        cntR++;
                        right--;
                    }

                    count += (long long)cntL * cntR;
                    left++;
                    right--;
                }
            }
        }

        return count;
    }
};

int main()
{
    return 0;
}