class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        if(k<=1) return 0;
        long long sum=0;
        long long res=0;
        int high=0,low=0,len;
        for(high; high<nums.size(); high++){
            len=high-low+1;
            sum+=nums[high];
            long long mul=sum*len;
            while(mul>=k && low<=high){
                sum=sum-nums[low++];
                len=high-low+1;
                mul=sum*len;
            }
            res+=high-low+1;
        }
        return res;
        
    }
};