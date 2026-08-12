class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> s_copy(26,0);
        vector<int> t_copy(26,0);
        for(int i=0; i<s.size(); i++){
            s_copy[s[i]-'a']++;
            t_copy[t[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if(s_copy[i]!=t_copy[i]) return false;

        }
        return true;
    }
};