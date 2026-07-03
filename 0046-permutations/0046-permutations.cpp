class Solution {
public:
    void fun(vector<int> &nums,int n,vector<int> &curr,vector<bool> &check,vector<vector<int>> &res){
        if(curr.size()==n){
            res.push_back(curr);
            return;
        }
        for(int i=0; i<n; i++){
            if(check[i]==true) continue;
            curr.push_back(nums[i]);
            check[i]=true;
            fun(nums,n,curr,check,res);
            curr.pop_back();
            check[i]=false;
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> res;
        vector<bool> check(n,false);
        vector<int> curr;
        fun(nums,n,curr,check,res);
        return res;
    }
};