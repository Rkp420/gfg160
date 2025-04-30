#include <iostream>
#include <unordered_set>
using namespace std;

// User function template for C++
class Solution
{
public:
    bool twoSum(vector<int> &arr, int target)
    {
        // code here
        unordered_set<int> seen;
        for (int num : arr)
        {
            int temp = target - num;

            if (seen.count(temp))
                return true;
            else
                seen.insert(num);
        }

        return false;
    }
};

int main()
{
    return 0;
}