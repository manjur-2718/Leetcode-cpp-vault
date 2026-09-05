class Solution {
public:
    void dfs(int row, int col, int m, int n, vector<vector<int>>& grid,
             vector<vector<int>>& vis) {
        vis[row][col] = 1;
        int x[4] = {-1, 1, 0, 0};
        int y[4] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int next_row = row + x[i];
            int next_col = col + y[i];
            if (next_row >= 0 && next_row < m && next_col >= 0 && next_col < n &&
             grid[next_row][next_col] == 1 && !vis[next_row][next_col]) {
                dfs(next_row, next_col, m, n, grid, vis);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 1 && !vis[0][i]) {
                dfs(0, i, m, n, grid, vis);
            }
            if (grid[m - 1][i] == 1 && !vis[m - 1][i]) {
                dfs(m - 1, i, m, n, grid, vis);
            }
        }

        // 2. First and last columns
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1 && !vis[i][0]) {
                dfs(i, 0, m, n, grid, vis);
            }
            if (grid[i][n - 1] == 1 && !vis[i][n - 1]) {
                dfs(i, n - 1, m, n, grid, vis);
            }
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    count++;
                }
            }
        }
        return count;
    }
};