#include <iostream>
using namespace std;

// Bruteforce

// User function template for C++

class Solution
{
public:
    bool isFound(vector<int> &arr, int i)
    {
        int low = 0, high = arr.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == i)
                return true;
            else if (arr[mid] > i)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return false;
    }
    int kthMissing(vector<int> &arr, int k)
    {
        // BruteForce
        // Range 1 to n + k;
        // Search For Each Element and Increase Your Count By 1
        // Whenever You find any missing No.
        // T.C => O((n + k) logN);
        
        int n = arr.size(), count = 0;


        for (int i = 1; i <= n + k; i++)
        {
            if (!isFound(arr, i))
                count++;
            if (count == k)
                return i;
        }

        return -1;
    }
};

int main()
{
    return 0;
}
