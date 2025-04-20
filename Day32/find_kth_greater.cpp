#include <iostream>
using namespace std;

// Using Previously explored Gap Method For Sorting Without Any Extra Space

class Solution
{
public:
    void swapIfGreater(vector<int> &a, vector<int> &b, int left, int right)
    {
        if (a[left] > b[right])
            swap(a[left], b[right]);
    }
    int kthElement(vector<int> &a, vector<int> &b, int k)
    {
        // code here
        int n = a.size();
        int m = b.size();
        int len = n + m;
        int gap = (len + 1) / 2;

        while (gap > 0)
        {
            int left = 0, right = left + gap;

            while (right < len)
            {

                // if we are in arr1 and arr2
                if (left < n && right >= n)
                {
                    swapIfGreater(a, b, left, right - n);
                }
                else if (left >= n)
                {
                    swapIfGreater(b, b, left - n, right - n);
                }
                else
                {
                    swapIfGreater(a, a, left, right);
                }

                right++;
                left++;
            }

            if (gap == 1)
                break;

            gap = (gap + 1) / 2;
        }

        // Now we have the sorted arrays without any extra Space
        if (k > n)
            return b[k - n - 1];
        else
            return a[k - 1];
    }
};

int main()
{
    return 0;
}