#include <iostream>
using namespace std;

// 1st Approach

class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat)
    {
        // code here
        int m = mat.size();
        int n = mat[0].size();

        vector<int> res;

        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        while (left <= right && top <= bottom)
        {

            // Case 1 : Top Insertion
            for (int i = left; i <= right; i++)
            {
                res.push_back(mat[top][i]);
            }
            top++;

            // Case 2 : Right Insertion
            for (int i = top; i <= bottom; i++)
            {
                res.push_back(mat[i][right]);
            }
            right--;

            // Case 3 : Bottom Insertion if Exists
            if (bottom >= top)
            {
                for (int i = right; i >= left; i--)
                {
                    res.push_back(mat[bottom][i]);
                }
                bottom--;
            }

            // Case 4 : Left Insertion if Exists
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    res.push_back(mat[i][left]);
                }
                left++;
            }
        }

        return res;
    }
};

// 2nd Approach

class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat)
    {
        // code here
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<int> res;

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        int row = 0, col = 0;
        int idx = 0;

        for (int i = 0; i < m * n; i++)
        {
            res.push_back(mat[row][col]);
            visited[row][col] = true;

            int newRow = row + dx[idx];
            int newCol = col + dy[idx];

            if (newRow >= 0 && newCol >= 0 && newRow < m && newCol < n && !visited[newRow][newCol])
            {

                row = newRow;
                col = newCol;
            }
            else
            {
                // Now it's Time to turn
                idx = (idx + 1) % 4; // 1-Based Indexing

                row += dx[idx];
                col += dy[idx];
            }
        }

        return res;
    }
};

int main()
{
    return 0;
}