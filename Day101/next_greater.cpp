#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> nextLargerElement(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> result(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; --i)
        {
            while (!st.empty() && st.top() <= arr[i])
            {
                st.pop();
            }

            if (!st.empty())
            {
                result[i] = st.top();
            }

            st.push(arr[i]);
        }

        return result;
    }
};

int main()
{
    return 0;
}