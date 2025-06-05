#include <iostream>
using namespace std;

// User function Template for C++

class Solution
{
public:
    vector<vector<int>> ans;
    bool isSafe(int row, int col, vector<int> &positions)
    {
        for (int prevCol = 0; prevCol < col; prevCol++)
        {
            int prevRow = positions[prevCol];
            if (prevRow == row || abs(prevRow - row) == abs(prevCol - col))
                return false;
        }

        return true;
    }

    void solve(int col, int n, vector<int> &positions)
    {
        if (col == n)
        {
            vector<int> solution;
            for (int r : positions)
                solution.push_back(r + 1);
            ans.push_back(solution);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, positions))
            {
                positions[col] = row;
                solve(col + 1, n, positions);
            }
        }
    }

    vector<vector<int>> nQueen(int n)
    {
        vector<int> positions(n, -1);
        solve(0, n, positions);
        return ans;
    }
};

int main()
{
    return 0;
}