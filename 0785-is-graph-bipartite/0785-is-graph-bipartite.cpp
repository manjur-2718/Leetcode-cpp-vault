class Solution {
public:
    bool dfs(int node, int col, vector<vector<int>>& graph, vector<int>& vis){
        vis[node] = col;
        for(int it:graph[node]){
            if(vis[it]==-1){
                if(dfs(it,!col,graph,vis)==false) return false;
            }
            else if(vis[it]==col) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,-1);
        for(int i=0; i<n; i++){
            if(vis[i]==-1){
                if(dfs(i,0,graph,vis)==false) return false;
            }
        }
        return true;
    }
};