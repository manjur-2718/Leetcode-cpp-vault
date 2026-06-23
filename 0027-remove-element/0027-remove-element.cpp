class Solution {
public:

    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        if(n==0) return 0;
        
        int count=0;
        int left=0;
        int right=0;
        while(right<n){
            if(nums[right]!=val){
                count++;
                nums[left++]=nums[right];
            }
            right++;
        }
        return count;
        
    }
};