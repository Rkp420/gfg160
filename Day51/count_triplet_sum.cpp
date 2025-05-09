#include <iostream>
using namespace std;

class Solution
{
public:
    int countTriplets(vector<int> &arr, int target)
    {
        int n = arr.size();
        int count = 0;
        const int MOD = 1e9 + 7;

        for (int i = 0; i < n - 2; i++)
        {
            int left = i + 1;
            int right = n - 1;
            int new_target = target - arr[i];

            while (left < right)
            {
                int sum = arr[left] + arr[right];

                if (sum == new_target)
                {
                    if (arr[left] != arr[right])
                    {
                        int left_count = 1;
                        int right_count = 1;

                        while (left + 1 < right && arr[left] == arr[left + 1])
                        {
                            left_count++;
                            left++;
                        }

                        while (right - 1 > left && arr[right] == arr[right - 1])
                        {
                            right_count++;
                            right--;
                        }

                        count += left_count * right_count;
                        left++;
                        right--;
                    }
                    else
                    {
                        int num = right - left + 1;
                        count += (num * (num - 1)) / 2;
                        break;
                    }
                }
                else if (sum < new_target)
                    left++;
                else
                    right--;
            }
        }

        return count;
    }
};

int main()
{
    return 0;
}