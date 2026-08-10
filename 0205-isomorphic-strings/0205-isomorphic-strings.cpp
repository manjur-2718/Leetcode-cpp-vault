class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char mapS[256] = {0};
        char mapT[256] = {0};
        for(int i=0; i<s.size(); i++){
            char c1 = s[i];
            char c2 = t[i];
            if(mapS[c1]!=0 && mapS[c1]!=c2) return false;
            if(mapT[c2]!=0 && mapT[c2]!=c1) return false;
            mapS[c1]=c2;
            mapT[c2]=c1;
        }
        return true;
    }
};