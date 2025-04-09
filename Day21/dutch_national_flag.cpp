#include <iostream>
using namespace std;

// Using Sorting

class Solution
{
public:
    void sort012(vector<int> &arr)
    {
        // code here
        sort(arr.begin(), arr.end());
    }
};

// Using count

class Solution
{
public:
    void sort012(vector<int> &arr)
    {
        // code here
        int count1 = 0;
        int count2 = 0;
        int count0 = 0;

        for (int &num : arr)
        {
            if (num == 0)
                count0++;
            else if (num == 1)
                count1++;
            else
                count2++;
        }

        for (int i = 0; i < count0; i++)
        {
            arr[i] = 0;
        }

        for (int i = 0; i < count1; i++)
        {
            arr[i + count0] = 1;
        }

        for (int i = 0; i < count2; i++)
        {
            arr[i + count1 + count0] = 2;
        }
    }
};

// Using Dutch National Flag Algo

class Solution
{
public:
    void sort012(vector<int> &arr)
    {
        // code here
        int n = arr.size();

        int low = 0;
        int mid = 0;
        int high = n - 1;

        while (mid <= high)
        {
            if (arr[mid] == 0)
            {
                swap(arr[mid], arr[low]);
                low++;
                mid++;
            }
            else if (arr[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(arr[high], arr[mid]);
                high--;
            }
        }
    }
};

int main()
{
    return 0;
}