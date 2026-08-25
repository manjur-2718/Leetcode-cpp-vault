class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};
    bool valid(int row, int col, int m, int n) {
        if (row < 0 || row >= m || col < 0 || col >= n)
            return false;
        return true;
    }
    void dfs(vector<vector<char>>& grid, int m, int n, int i, int j,
             vector<vector<bool>>& visited) {
        visited[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int row = i + x[k];
            int col = j + y[k];
            if (valid(row, col, m, n) && grid[row][col] == '1' &&
                visited[row][col] == 0) {
                dfs(grid, m, n, row, col, visited);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && visited[i][j] == 0) {
                    dfs(grid, m, n, i, j, visited);
                    res++;
                }
            }
        }
        return res;
    }
};