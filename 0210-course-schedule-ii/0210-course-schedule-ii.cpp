class Solution {
public:
vector<int> res;
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& path){
        vis[node]=1;
        path[node]=1;
        for(int it:adj[node]){
            if(vis[it]==0){
                if(dfs(it,adj,vis,path)==true) return true;
            }
            else if(path[it]) return true;
        }
        path[node]=0;
        res.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto pre:prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }
        vector<int> vis(numCourses,0);
        vector<int> path(numCourses,0);

        for(int i=0; i<numCourses; i++){
            if(vis[i]==0){
                if(dfs(i,adj,vis,path)) return {};
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};