#include <iostream>
using namespace std;

// User function Template for C++
class Solution
{
public:
    void setMatrixZeroes(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        bool rowZero = false, colZero = false;

        for (int j = 0; j < m; j++)
        {
            if (mat[0][j] == 0)
                rowZero = true;
        }

        for (int i = 0; i < n; i++)
        {
            if (mat[i][0] == 0)
                colZero = true;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (mat[i][0] == 0 || mat[0][j] == 0)
                {
                    mat[i][j] = 0;
                }
            }
        }

        if (rowZero)
        {
            for (int j = 0; j < m; j++)
                mat[0][j] = 0;
        }

        if (colZero)
        {
            for (int i = 0; i < n; i++)
                mat[i][0] = 0;
        }
    }
};

int main()
{
    return 0;
}