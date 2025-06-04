#include <iostream>
#include <set>
using namespace std;

class Solution
{
public:
    void permute(string &s, int index, set<string> &permutations)
    {
        if (index == s.size())
        {
            permutations.insert(s);
            return;
        }

        for (int i = index; i < s.size(); i++)
        {
            swap(s[i], s[index]);
            permute(s, index + 1, permutations);
            swap(s[i], s[index]);
        }
    }

    vector<string> findPermutation(string &s)
    {
        set<string> permutations;
        permute(s, 0, permutations);

        return vector<string>(permutations.begin(), permutations.end());
    }
};

int main()
{
    return 0;
}