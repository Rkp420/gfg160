#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> make_lps(string &s)
    {
        int n = s.size();
        vector<int> lps(n);

        lps[0] = 0;
        int len = 0, i = 1;

        while (i < n)
        {
            if (s[i] == s[len])
            {
                len++;
                lps[i++] = len;
            }
            else
            {
                if (len != 0)
                    len = lps[len - 1];
                else
                    lps[i++] = 0;
            }
        }

        return lps;
    }

    bool areRotations(string &s1, string &s2)
    {

        int n = s1.size();
        int m = s2.size();

        if (n != m)
            return false;

        string newString = s1 + s1;

        vector<int> lps = make_lps(s2);

        int i = 0;
        int j = 0;

        while (i < newString.size())
        {
            if (newString[i] == s2[j])
            {
                i++;
                j++;
            }
            else
            {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }

            if (j == m)
                return true;
        }

        return false;
    }
};

class Solution
{
public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2)
    {
        // Your code here
        int n = s1.size();
        int m = s2.size();

        if (n != m)
            return false;

        for (int i = 0; i < n; i++)
        {

            if (s1 == s2)
                return true;

            char last = s1.back();
            s1.pop_back();
            s1 = last + s1;
        }

        return false;
    }
};

int main()
{
    return 0;
}