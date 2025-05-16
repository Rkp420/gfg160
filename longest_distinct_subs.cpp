#include <iostream>
using namespace std;

class Solution
{
public:
    int longestUniqueSubstr(string &s)
    {

        unordered_map<char, int> lastIndex;
        int start = 0, maxLen = 0;

        for (int end = 0; end < s.size(); end++)
        {
            char ch = s[end];

            if (lastIndex.count(ch) && lastIndex[ch] >= start)
                start = lastIndex[ch] + 1;

            lastIndex[ch] = end;
            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};

int main()
{
    return 0;
}