class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix=strs[0];
        int size=INT_MAX;
        for(auto word:strs){
            int i=0;
            for(auto it:word){
                if(prefix[i]==it) i++;
                else break;
            }
            size=min(size,i);
        }
        return prefix.substr(0,size);
    }
};