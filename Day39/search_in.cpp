#include <iostream>
using namespace std;

class Solution
{
public:
    bool goAndSearch(vector<int> &row, int x)
    {
        int low = 0, high = row.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - mid) / 2;

            if (row[mid] == x)
                return true;

            else if (row[mid] > x)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return false;
    }
    bool searchRowMatrix(vector<vector<int>> &mat, int x)
    {
        // code here
        for (vector<int> &row : mat)
        {
            bool isFound = goAndSearch(row, x);

            if (isFound)
                return true;
        }

        return false;
    }
};


int main()
{
    return 0;
}