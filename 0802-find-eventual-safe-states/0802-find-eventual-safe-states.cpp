class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adjRev(n);
        vector<int> inDegree(n,0);
        for(int i=0; i<n; i++){
            for(int it:graph[i]){
                adjRev[it].push_back(i);
                inDegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        vector<int> res;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            res.push_back(node);
            for(int it:adjRev[node]){
                inDegree[it]--;
                if(inDegree[it]==0) q.push(it);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};