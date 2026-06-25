class Solution {
public:
    bool check(vector<int> &have,vector<int> &need){
        for(int i=0; i<128; i++){
            if(have[i]<need[i]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int m=s.size();
        int n = t.size();
        if(m==0 || n==0 || m<n) return "";
        vector<int> have(128,0);
        vector<int> need(128,0);
        for(auto it:t){
            need[it]++;
        }
        int low=0,high=0,res=INT_MAX;
        int start=-1;

        for(high;high<m;high++){
            have[s[high]]++;
            while(check(have,need)){
                int len=high-low+1;
                if(res>len){
                    res=len;
                    start=low;
                }
                have[s[low]]--;
                low++;
            }
        }
        if(res==INT_MAX) return "";
        return s.substr(start,res);
    
        
    }
};