struct cmp{
    bool operator()(pair<int,int> &a, pair<int,int> &b){
        if(a.first!=b.first){
            return a.first<b.first;
        }
        return a.second<b.second;
    }
};
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        int row=0;
        for(auto it:mat){
            int count=0;
            for(auto el:it){
                if(el==1) count++;
            }
            pq.push({count,row});
            if(pq.size()>k){
                pq.pop();

            }
            row++;
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};