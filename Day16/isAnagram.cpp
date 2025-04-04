#include <iostream>
using namespace std;

class Solution
{
public:
    bool areAnagrams(string &s1, string &s2)
    {

        // Another By Using Sorting
        // T.c => O(nlogn + mlogm + n);
        // S.c => O(1)

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        if (s1 == s2)
            return true;

        return false;
    }
};

class Solution
{
public:
    bool areAnagrams(string &s1, string &s2)
    {

        // Using UnOrdered Map For Frequency of Characters
        // T.c -> O(N + M + 26);
        // S.c -> O(26);

        unordered_map<char, int> m;

        for (int i = 0; i < s1.length(); i++)
        {
            m[s1[i]]++;
        }

        for (int j = 0; j < s2.length(); j++)
        {
            m[s2[j]]--;
        }

        for (auto &it : m)
        {
            if (it.second != 0)
                return false;
        }

        return true;
    }
};

class Solution
{
public:
    bool areAnagrams(string &s1, string &s2)
    {

        // simple Using Freq Array
        // T.c -> O(N + M + 26);
        // S.c -> O(26);

        vector<int> freqArr(26, 0);

        for (int i = 0; i < s1.length(); i++)
        {
            int idx = s1[i] - 'a';
            freqArr[idx]++;
        }

        for (int j = 0; j < s2.length(); j++)
        {
            int idx = s2[j] - 'a';
            freqArr[idx]--;
        }

        for (int k = 0; k < 26; k++)
        {
            if (freqArr[k] != 0)
                return false;
        }

        return true;
    }
};

int main()
{
    return 0;
}