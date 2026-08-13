class Solution {
public:
    const int min_val = INT_MIN;
    const int max_val = INT_MAX;
    int myAtoi(string s) {
        int i=0;
        long long res=0;
        int sign=1;
        while(i<s.size() && s[i]==' ') i++;

        if(i<s.size() && (s[i]=='+' || s[i]=='-')){
            if(s[i]=='-') sign=-1;
            i++;
        }

        if(i<s.size()){
            for(i; i<s.size(); i++){
                if(!isdigit(s[i])){
                    return (sign*(int)res);
                }
                res=res*10+(s[i]-'0');
                if(sign*res<=min_val) return min_val;
                if(sign*res>=max_val) return max_val;
            }
        }
        return (int)(sign*res);
    }
};