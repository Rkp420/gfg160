#include <iostream>
using namespace std;

class Solution
{
public:
    bool dfs(int i, int j, int idx, vector<vector<char>> &mat, string &word, vector<vector<bool>> &visited)
    {
        if (idx == word.size())
            return true;

        int n = mat.size();
        int m = mat[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || mat[i][j] != word[idx])
            return false;

        visited[i][j] = true;

        bool found = dfs(i + 1, j, idx + 1, mat, word, visited) ||
                     dfs(i - 1, j, idx + 1, mat, word, visited) ||
                     dfs(i, j + 1, idx + 1, mat, word, visited) ||
                     dfs(i, j - 1, idx + 1, mat, word, visited);

        visited[i][j] = false;
        return found;
    }

    bool isWordExist(vector<vector<char>> &mat, string &word)
    {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == word[0])
                {
                    if (dfs(i, j, 0, mat, word, visited))
                        return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    return 0;
}