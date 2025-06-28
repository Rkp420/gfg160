#include <iostream>
using namespace std;

class Solution
{
public:
    int maxLength(string &s)
    {
        int maxLen = 0;

        int open = 0, close = 0;
        for (char ch : s)
        {
            if (ch == '(')
                open++;
            else if (ch == ')')
                close++;

            if (open == close)
                maxLen = max(maxLen, 2 * close);
            else if (close > open)
            {
                open = close = 0;
            }
        }

        open = close = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '(')
                open++;
            else if (s[i] == ')')
                close++;

            if (open == close)
            {
                maxLen = max(maxLen, 2 * open);
            }
            else if (open > close)
            {
                open = close = 0;
            }
        }

        return maxLen;
    }
};

int main()
{
    return 0;
}