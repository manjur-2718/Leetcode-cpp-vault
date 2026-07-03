class Solution {
public:
    void fun(vector<int> &candidates,int n,int idx,int sum,vector<int> &record,vector<vector<int>> &res,int target){
        if(sum==target){
            res.push_back(record);
            return;
        }
        if(idx==n || sum>target) return;
        fun(candidates,n,idx+1,sum,record,res,target);
        if(sum+candidates[idx]<=target){
            sum+=candidates[idx];
            record.push_back(candidates[idx]);
            fun(candidates,n,idx,sum,record,res,target);
            record.pop_back();
            sum-=candidates[idx];
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int> record;
        vector<vector<int>> res;
        fun(candidates,n,0,0,record,res,target);
        return res;
    }
};