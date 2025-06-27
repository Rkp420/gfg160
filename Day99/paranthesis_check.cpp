#include <iostream>
using namespace std;

class Solution
{
public:
    bool isBalanced(string &k)
    {

        stack<char> st;
        for (char ch : k)
        {
            if (ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }
            else
            {
                if (st.empty())
                    return false;

                char top = st.top();
                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '['))
                {
                    return false;
                }
                st.pop();
            }
        }

        return st.empty();
    }
};

int main()
{
    return 0;
}