class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(vis[it]==0){
                dfs(it,adj,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adjLs(n);
        vector<int> visited(n,0);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjLs[i].push_back(j);
                }
            }
        }

        int count =0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i,adjLs,visited);
                count++;
            }
        }
        return count;
    }
};