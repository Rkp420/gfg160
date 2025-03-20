//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends

// User function template for C++
class Solution
{
public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr)
    {
        // Code Here
        int secondLargest = -1;
        int largest = -1;

        for (int num : arr)
        {
            if (num > largest)
            {
                secondLargest = largest;
                largest = num;
            }
            else if (num < largest && num > secondLargest)
            {
                secondLargest = num;
            }
        }

        return secondLargest;
    }
};

//{ Driver Code Starts.

int main()
{
    return 0;
}

// } Driver Code Ends