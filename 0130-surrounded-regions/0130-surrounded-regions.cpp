class Solution {
public:
    void dfs(int row, int col, int m, int n, vector<vector<char>>& board,
             vector<vector<int>>& vis) {
        vis[row][col] = 1;
        int x[4] = {-1, 1, 0, 0};
        int y[4] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int next_row = row + x[i];
            int next_col = col + y[i];
            if (next_row >= 0 && next_row < m && next_col >= 0 && next_col < n &&
                board[next_row][next_col] == 'O' && !vis[next_row][next_col]) {
                dfs(next_row, next_col, m, n, board, vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O' && !vis[0][i]) {
                dfs(0, i, m, n, board, vis);
            }
            if (board[m - 1][i] == 'O' && !vis[m - 1][i]) {
                dfs(m - 1, i, m, n, board, vis);
            }
        }

        // 2. First and last columns
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O' && !vis[i][0]) {
                dfs(i, 0, m, n, board, vis);
            }
            if (board[i][n - 1] == 'O' && !vis[i][n - 1]) {
                dfs(i, n - 1, m, n, board, vis);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};