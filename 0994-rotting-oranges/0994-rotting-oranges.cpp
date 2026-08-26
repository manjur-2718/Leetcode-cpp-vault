class Solution {
public:
    const int x[4] = {-1,1,0,0};
    const int y[4] = {0,0,-1,1};
    bool valid(int m, int n, int row,int col){
        if(row<0 || row>=m || col<0 || col>=n) return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh=0;
        int time=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1) fresh++;
                if(grid[i][j]==2){
                    q.push({i,j});
                    grid[i][j]=-1;
                }
            }
        }
        while(!q.empty() && fresh>0){
            time++;
            int size=q.size();
            while(size--){
                auto node = q.front();
                q.pop();
                int row=node.first;
                int col=node.second;
                for(int i=0; i<4; i++){
                    int next_row = row+x[i];
                    int next_col=col+y[i];
                    if(valid(m,n,next_row,next_col) && grid[next_row][next_col]==1){
                        q.push({next_row,next_col});
                        grid[next_row][next_col]=-1;
                        fresh--;
                    }
                }
            }
        }
        if(fresh>0) return -1;
        return time;
    }
};