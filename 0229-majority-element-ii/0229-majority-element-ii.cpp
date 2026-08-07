class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1=0;
        int num2=1;
        int count1=0;
        int count2=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==num1) count1++;
            else if(nums[i]==num2) count2++;
            else if(count1==0){
                num1=nums[i];
                count1=1;
            }
            else if(count2==0){
                num2=nums[i];
                count2=1;
            }
            else{
                count1--;
                count2--;
            }
        }
        int check1=num1;
        int check2=num2;
        int countCheck1=0;
        int countCheck2=0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==check1) countCheck1++;
            else if(nums[i]==check2) countCheck2++;
        }
        vector<int> res;
        if(nums.size()/3<countCheck1) res.push_back(num1);
        if(nums.size()/3<countCheck2) res.push_back(num2);
        return res;
    }
};