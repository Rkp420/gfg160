//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends

// User function template for C++
class Solution
{
public:
    void pushZerosToEnd(vector<int> &arr)
    {
        // code here
        int low = 0;
        int i = 0;
        while (i < arr.size())
        {
            if (arr[i] != 0)
            {
                swap(arr[low], arr[i]);
                low++;
            }
            i++;
        }
    }
};

//{ Driver Code Starts.
int main()
{
    return 0;
}
// } Driver Code Ends