#include <iostream>
using namespace std;

// BruteForce and Optimal

class Solution
{
public:
    int myAtoi(char *s)
    {
        // Your code here
        int i = 0;
        while (s[i] == ' ')
            i++;

        int sign = 1;

        if (s[i] == '-' || s[i] == '+')
        {
            if (s[i++] == '-')
                sign = -1;
        }

        int res = 0;

        while (s[i] >= '0' && s[i] <= '9')
        {
            int digit = s[i] - '0';

            if (res > (INT_MAX / 10) || ((res == INT_MAX / 10) && s[i] - '0' > 7))
            {
                return sign == -1 ? INT_MIN : INT_MAX;
            }

            res = res * 10 + digit;
            i++;
        }

        return res * sign;
    }
};

class Solution
{
public:
    int myAtoi(char *s)
    {
        // Your code here
        int i = 0;
        while (s[i] == ' ')
            i++;

        int sign = 1;

        if (s[i] == '-' || s[i] == '+')
        {
            if (s[i++] == '-')
                sign = -1;
        }

        int res = 0;

        while (s[i] >= '0' && s[i] <= '9')
        {
            int digit = s[i] - '0';

            if (res > (INT_MAX / 10) || ((res == INT_MAX / 10) && res + digit > INT_MAX))
            {
                return sign == -1 ? INT_MIN : INT_MAX;
            }

            res = res * 10 + digit;
            i++;
        }

        return res * sign;
    }
};

int main()
{
    return 0;
}