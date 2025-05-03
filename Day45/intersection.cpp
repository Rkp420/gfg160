#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<int> intersectionWithDuplicates(vector<int> &a, vector<int> &b)
    {

        unordered_set<int> temp;

        unordered_set<int> seen;
        for (int num : a)
            seen.insert(num);

        for (int num : b)
        {
            if (seen.count(num))
                temp.insert(num);
        }

        vector<int> ans(temp.begin(), temp.end());

        return ans;
    }
};

int main()
{
    return 0;
}