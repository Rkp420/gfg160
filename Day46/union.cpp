#include <iostream>
#include <set>
using namespace std;

class Solution
{
public:
    int findUnion(vector<int> &a, vector<int> &b)
    {
        set<int> unique;

        for (int num : a)
            unique.insert(num);
        for (int num : b)
            unique.insert(num);

        return unique.size();
    }
};

int main()
{
    return 0;
}