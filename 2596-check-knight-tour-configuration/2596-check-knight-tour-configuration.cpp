class Solution {
public:
    bool dfs(vector<vector<int>>& grid, int r, int c, int n, int expval)
    {
        if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != expval)
        {
            return false;
        }

        if (expval == n * n - 1)
        {
            return true;
        }

        bool ans1 = dfs(grid, r - 2, c + 1, n, expval + 1);
        bool ans2 = dfs(grid, r - 1, c + 2, n, expval + 1);
        bool ans3 = dfs(grid, r + 1, c + 2, n, expval + 1);
        bool ans4 = dfs(grid, r + 2, c + 1, n, expval + 1);
        bool ans5 = dfs(grid, r + 2, c - 1, n, expval + 1);
        bool ans6 = dfs(grid, r + 1, c - 2, n, expval + 1);
        bool ans7 = dfs(grid, r - 1, c - 2, n, expval + 1);
        bool ans8 = dfs(grid, r - 2, c - 1, n, expval + 1);

        return ans1 || ans2 || ans3 || ans4 ||
               ans5 || ans6 || ans7 || ans8;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] != 0)
            return false;

        return dfs(grid, 0, 0, n, 0);
    }
};