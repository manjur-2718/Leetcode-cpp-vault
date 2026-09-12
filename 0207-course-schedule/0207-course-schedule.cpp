class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& path){
        vis[node]=1;
        path[node]=1;
        for(int it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,path)) return true;
            }
            else if(path[it]==1) return true;
        }
        path[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> vis(numCourses,0);
        vector<int> path(numCourses,0);
        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,path)) return false;
            }
        }
        return true;
    }    
};