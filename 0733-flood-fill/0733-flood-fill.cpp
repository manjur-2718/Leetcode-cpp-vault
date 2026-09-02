class Solution {
public:
    const int x[4] = {-1,1,0,0};
    const int y[4] = {0,0,-1,1};
    bool valid(int m, int n, int row,int col){
        if(row<0 || row>=m || col<0 || col>=n) return false;
        return true;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int target = image[sr][sc];
        if(target == color) return image;

        queue<pair<int,int>> q;
        int m = image.size();
        int n = image[0].size();
        q.push({sr,sc});
        image[sr][sc] =color;

        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto node = q.front();
                q.pop();
                int row=node.first;
                int col=node.second;
                for(int i=0; i<4; i++){
                    int next_row = row+x[i];
                    int next_col=col+y[i];
                    if(valid(m,n,next_row,next_col) && image[next_row][next_col]==target){
                        image[next_row][next_col] = color;
                        q.push({next_row,next_col});
                    }
                }
            }
        }
        return image;
    }
};