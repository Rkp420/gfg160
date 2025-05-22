#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &arr)
    {

        int n = arr.size();
        vector<int> suffixMul(n, 1);
        for (int i = n - 2; i >= 0; i--)
        {
            suffixMul[i] = suffixMul[i + 1] * arr[i + 1];
        }

        int leftMul = 1;
        vector<int> ans(n, 1);
        for (int i = 0; i < n; i++)
        {
            ans[i] = leftMul * suffixMul[i];
            leftMul *= arr[i];
        }

        return ans;
    }
};

int main()
{
    return 0;
}