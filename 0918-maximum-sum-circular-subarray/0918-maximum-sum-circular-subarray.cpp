class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int sum=nums[0];
        int max_subarray=nums[0];
        int min_subarray=nums[0];
        int min_end=nums[0];
        int max_end=nums[0];
        for(int i=1; i<n; i++){
            max_end=max(max_end+nums[i],nums[i]);
            min_end=min(min_end+nums[i],nums[i]);
            sum+=nums[i];

            max_subarray=max(max_subarray,max_end);
            min_subarray=min(min_subarray,min_end);
        }

        if(max_subarray<0) return max_subarray;

        return max(max_subarray,sum-min_subarray);
    }
};