#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> maxOfMins(vector<int> &arr)
    {

        int n = arr.size();
        vector<int> ans(n, 0);

        stack<int> st;

        vector<int> len(n, 0);

        for (int i = 0; i < n; i++)
        {

            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                int top = st.top();
                st.pop();
                int windowSize = st.empty() ? i : i - st.top() - 1;
                len[top] = windowSize;
            }
            st.push(i);
        }

        while (!st.empty())
        {
            int top = st.top();
            st.pop();
            int windowSize = st.empty() ? n : n - st.top() - 1;
            len[top] = windowSize;
        }

        for (int i = 0; i < n; i++)
        {
            int windowSize = len[i] - 1;
            ans[windowSize] = max(ans[windowSize], arr[i]);
        }

        for (int i = n - 2; i >= 0; i--)
        {
            ans[i] = max(ans[i], ans[i + 1]);
        }

        return ans;
    }
};

int main()
{
    return 0;
}