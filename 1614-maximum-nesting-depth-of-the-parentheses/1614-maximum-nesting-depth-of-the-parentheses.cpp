class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int res=0;
        for(char c:s){
            if(c=='('){
                count++;
                res=max(res,count);
            }
            else if(c==')'){
                count--;
                res=max(res,count);
            }
        }
        return res;
    }
};