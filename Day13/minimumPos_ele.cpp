#include <iostream>
using namespace std;

// Approaches
 /**
  * 
  * [Naive approach] By Sorting - O(n *log n) Time and O(n) Space
  * [Better approach] Using Visited Array - O(n) Time and O(n) Space
  * [Expected Approach] Using Cycle Sort - O(n) Time and O(1) Space
  * [Alternate Approach] By Negating Array Elements – O(n) Time and O(1) Space
  * [Alternate Approach] By Marking Indices – O(n) Time and O(1) Space 
  * 
  * */

class Solution
{
public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr)
    {
        // Your code here
        // BruteForce : Do a Linear Search For Every Possible Integer
        // T.c => O(n * 10^6) --> T.L.E

        // Better Approch : Using Sorting
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int smallestPos = 1;

        int i = 0;
        while (i < n)
        {
            if (arr[i] == smallestPos)
                smallestPos++;
            else if (arr[i] > smallestPos)
                break;
            i++;
        }

        return smallestPos;
    }
};

class Solution
{
public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr)
    {
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            while (arr[i] > 0 && arr[i] <= n && arr[i] != arr[arr[i] - 1])
                swap(arr[i], arr[arr[i] - 1]);
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] != i + 1)
                return i + 1;
        }

        return n + 1;
    }
};

int main()
{
    return 0;
}