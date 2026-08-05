class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        string result="";
        for(char c:s){
            if(c=='('){
                cnt++;
                if(cnt>1) result.push_back('(');
            }
            if(c==')'){
                cnt--;
                if(cnt>0) result.push_back(')');
            }
        }
        return result;
    }
};