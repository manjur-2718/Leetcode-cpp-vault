class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int ans=INT_MAX;
        vector<int> have(26,0);
        for(char c:text){
            have[c-'a']++;
        }

        vector<int> need(26,0);
        string need_st="balloon";
        for(char c:need_st){
            need[c-'a']++;
        }

        for(int i=0; i<7; i++){
            if(have[need_st[i]-'a']>=need[need_st[i]-'a']){
                ans=min(ans,have[need_st[i]-'a']/need[need_st[i]-'a']);
            }
            else{
                return 0;
            }
        }
        return ans;
        
    }
};