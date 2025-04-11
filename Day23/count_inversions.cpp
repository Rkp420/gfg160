#include <iostream>
using namespace std;

// Bruteforce

class Solution
{
public:
    int inversionCount(vector<int> &arr)
    {
        // Your Code Here
        int n = arr.size();
        int res = 0;

        for (int i = 0; i < n - 1; i++)
        {
            int count = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] > arr[j])
                    count++;
            }
            res += count;
        }

        return res;
    }
};

// Using Merge Sort

class Solution
{
public:
    int mergeSort(vector<int> &arr, int l, int r)
    {
        if (l >= r)
            return 0;

        int mid = (l + r) / 2;

        int inv = mergeSort(arr, l, mid);
        inv += mergeSort(arr, mid + 1, r);
        inv += merge(arr, l, mid, r);

        return inv;
    }

    int merge(vector<int> &arr, int l, int mid, int r)
    {
        int i = l, j = mid + 1, k = 0, inv = 0;

        vector<int> temp(r - l + 1);

        while (i <= mid && j <= r)
        {
            if (arr[i] <= arr[j])
            {
                temp[k++] = arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];
                inv += mid - i + 1;
            }
        }

        while (i <= mid)
            temp[k++] = arr[i++];
        while (j <= r)
            temp[k++] = arr[j++];

        for (int m = 0; m < k; m++)
            arr[l + m] = temp[m];

        return inv;
    }

    int inversionCount(vector<int> &arr)
    {
        int n = arr.size();
        return mergeSort(arr, 0, n - 1);
    }
};

int main()
{
    return 0;
}