class Solution {
public:
vector<string> fun(int n,int open,int close,vector<string> &temp,vector<string> &res){
    if(open==n && close==n){
        string s="";
        for(auto it:temp){
            s+=it;
        }
        res.push_back(s);
    }
    if(open<n){
        temp.push_back("(");
        fun(n,open+1,close,temp,res);
        temp.pop_back();
    }
    if(close<open){
        temp.push_back(")");
        fun(n,open,close+1,temp,res);
        temp.pop_back();
    }
    return res;
}
    vector<string> generateParenthesis(int n) {
        vector<string> res,temp;
        return fun(n,0,0,temp,res);
    }
};