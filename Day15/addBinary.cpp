#include <iostream>
using namespace std;

// User function template for C++
class Solution
{
public:
    string addBinary(string &s1, string &s2)
    {
        // your code here
        int n = s1.length();
        int m = s2.length();

        // BruteForce

        if (n > m)
            s2 = string(n - m, '0') + s2;
        if (n < m)
            s1 = string(m - n, '0') + s1;

        int carry = 0;
        string ans = "";
        for (int i = s1.size() - 1; i >= 0; i--)
        {
            int sum = (s1[i] - '0') + (s2[i] - '0') + carry;

            ans.push_back((sum % 2) + '0');

            carry = sum / 2;
        }

        if (carry)
            ans.push_back('1');

        reverse(ans.begin(), ans.end());

        size_t pos = ans.find_first_not_of('0');
        if (pos == string::npos)
            return "0";

        return ans.substr(pos);
    }
};

int main()
{
    return 0;
}