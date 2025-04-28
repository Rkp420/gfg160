#include <iostream>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &mat, int x)
    {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = n * m - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            int i = mid / m;
            int j = mid % m;

            if (mat[i][j] == x)
                return true;
            else if (mat[i][j] < x)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return false;
    }
};

int main()
{
    return 0;
}