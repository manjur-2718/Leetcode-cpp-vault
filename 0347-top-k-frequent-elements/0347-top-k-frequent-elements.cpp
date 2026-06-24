struct cmp{
    bool operator()(pair<int,int> &a,pair<int,int> &b){
        if(a.first!=b.first){
            return a.first>b.first;
        }
        return a.second>b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1) return {nums[0]};
        unordered_map<int,int> mpp;
        for(int it:nums){
            mpp[it]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> pq;

        for(auto it:mpp){
            int freq=it.second;
            int el=it.first;
            pair<int,int> curr={freq,el};
            if(pq.size()<k){
                pq.push(curr);
                continue;
            }

            if(curr.first>pq.top().first){
                pq.pop();
                pq.push(curr);
            }
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();   
        }
        return ans;
    }
};

