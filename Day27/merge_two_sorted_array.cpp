#include <iostream>
using namespace std;

class Solution
{
public:
    void mergeArrays(vector<int> &a, vector<int> &b)
    {

        // First Technique
        int n = a.size(), m = b.size();
        int i = n - 1;
        int j = 0;
        while (i >= 0 && j < m)
        {
            if (a[i] > a[j])
            {
                swap(a[i], a[j]);
                i--;
                j++;
            }
            else
                break;
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    }
};


// 2nd Technique : Using Gap Method

class Solution
{
public:
    void swapIfGreater(vector<int> &a, vector<int> &b, int left, int right)
    {
        if (a[left] > b[right])
        {
            swap(a[left], b[right]);
        }
    }
    void mergeArrays(vector<int> &a, vector<int> &b)
    {

        // 2nd Technique : Using Gap Method
        int n = a.size(), m = b.size();
        int len = n + m;
        int gap = (len / 2) + (len % 2);

        while (gap > 0)
        {
            int left = 0;
            int right = left + gap;

            while (right < len)
            {

                // If We are on the arr1 and arr2
                if (left < n && right >= n)
                {
                    swapIfGreater(a, b, left, right - n);
                } // If we are on the arr2 and arr2
                else if (left >= n)
                {
                    swapIfGreater(b, b, left - n, right - n);
                }
                // if We are on the arr1 and arr1
                else
                {
                    swapIfGreater(a, a, left, right);
                }

                left++;
                right++;
            }

            if (gap == 1)
                break;

            gap = (gap / 2) + (gap % 2);
        }
    }
};

// Using Brute Force

class Solution
{
public:
    void mergeArrays(vector<int> &a, vector<int> &b)
    {

        for (int i = b.size() - 1; i >= 0; i--)
        {

            if (a.back() > b[i])
            {

                int last = a.back();
                int j = a.size() - 2;
                while (j >= 0 && a[j] > b[i])
                {
                    a[j + 1] = a[j];
                    j--;
                }

                a[j + 1] = b[i];
                b[i] = last;
            }
        }
    }
};

int main()
{
    return 0;
}