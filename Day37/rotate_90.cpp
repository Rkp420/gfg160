#include <iostream>
using namespace std;

class Solution
{
public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>> &mat)
    {
        // Using a Temporary Grid
        int n = mat.size();

        vector<vector<int>> temp(n, vector<int>(n));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                temp[n - j - 1][i] = mat[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mat[i][j] = temp[i][j];
            }
        }
    }
};

int main()
{
    return 0;
}