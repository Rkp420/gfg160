#include <iostream>
using namespace std;

// BruteForce

class Solution
{
public:
    bool isPal(string &s, int j)
    {
        int i = 0;
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }

        return true;
    }
    int minChar(string &s)
    {
        // Write your code here
        int n = s.size();

        int i = n - 1;
        while (i >= 0)
        {
            if (isPal(s, i))
                return n - i - 1;
            else
                i--;
        }

        return -1;
    }
};

// Using Kmp

class Solution
{
public:
    vector<int> make_lps(string &s)
    {
        int n = s.length();
        vector<int> lps(n);

        lps[0] = 0;
        int len = 0;

        int i = 1;
        while (i < s.size())
        {
            if (s[i] == s[len])
            {
                len++;
                lps[i] = len;
                i++;
            }

            else
            {
                if (len != 0)
                    len = lps[len - 1];
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    int minChar(string &s)
    {
        // Write your code here
        int n = s.size();

        string rev = s;
        reverse(rev.begin(), rev.end());

        // New String
        s = s + '$' + rev;

        vector<int> lps = make_lps(s);

        return n - lps.back();
    }
};

int main()
{
    return 0;
}