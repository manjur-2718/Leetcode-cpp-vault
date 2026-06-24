struct cmp{
    bool operator()(const pair<int,int>& a, const pair<int,int>& b){
        if(a.second!=b.second){
            return a.second < b.second;
        }
        return a.first>b.first;
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> pq;
        for(auto it:points){
            int x=it[0];
            int y=it[1];
            int dist=(x*x)+(y*y);

            pq.push({dist,it});
            if(pq.size()>k){
                pq.pop();

            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};