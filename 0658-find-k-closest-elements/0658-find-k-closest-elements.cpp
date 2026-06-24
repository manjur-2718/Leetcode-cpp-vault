struct cmp{
    bool operator()(pair<int,int>& a,pair<int,int>& b){
        if(a.first!=b.first){
            return a.first < b.first;
        }
        return a.second<b.second;
    }
};
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        for(int it:arr){
            int dist=abs(it-x);
            pq.push({dist,it});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};