class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi=0;
        int sum=0;
        for(int it:gain){
            sum+=it;
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};