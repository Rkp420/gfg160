#include <iostream>
using namespace std;

// BruteForce
class Solution
{
public:
    char nonRepeatingChar(string &s)
    {

        int n = s.size();
        if (n == 1)
            return s[0];

        // BruteForce
        for (int i = 0; i < n - 1; i++)
        {
            char curr = s[i];
            bool flag = false;
            for (int j = 0; j < n; j++)
            {
                if (i != j && s[i] == s[j])
                {
                    flag = true;
                    break;
                }
            }

            if (flag == false)
                return curr;
        }

        return '$';
    }
};

class Solution
{
public:
    char nonRepeatingChar(string &s)
    {

        int n = s.size();
        if (n == 1)
            return s[0];

        // Using Freq Array
        vector<int> vis(26, -1);

        for (int i = 0; i < n; i++)
        {
            int idx = s[i] - 'a';

            if (vis[idx] == -1)
            {
                // First Time Visited this Element
                // Storing Where it has been seen For the First time
                vis[idx] = i;
            }
            else
            {
                // Set any Random Value which tells that it has been seen Earlier and
                // It is an Duplicate
                vis[idx] = -2;
            }
        }

        int minIdx = INT_MAX;

        for (int i = 0; i < 26; i++)
        {
            if (vis[i] >= 0 && vis[i] < minIdx)
                minIdx = vis[i];
        }

        return (minIdx == INT_MAX) ? '$' : s[minIdx];
    }
};

class Solution
{
public:
    char nonRepeatingChar(string &s)
    {

        int n = s.size();
        if (n == 1)
            return s[0];

        // BruteForce
        vector<int> freq(26, 0);

        for (char &ch : s)
            freq[ch - 'a']++;

        for (char &ch : s)
        {
            if (freq[ch - 'a'] == 1)
                return ch;
        }

        return '$';
    }
};

int main()
{
    return 0;
}