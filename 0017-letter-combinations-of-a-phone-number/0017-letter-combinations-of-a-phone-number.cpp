class Solution {
public:
    void fun(string &digits,int idx,int n,string &prev,unordered_map<char,string> mpp,vector<string> &res){
        if(idx==n){
            res.push_back(prev);
        }
        string s=mpp[digits[idx]];
        for(int i=0; i<s.size(); i++){
            prev.push_back(s[i]);
            fun(digits,idx+1,n,prev,mpp,res);
            prev.pop_back();
        }
        return;
    } 
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        vector<string> res;
        unordered_map<char,string> mpp;
        mpp['2']="abc";
        mpp['3']="def";
        mpp['4']="ghi";
        mpp['5']="jkl";
        mpp['6']="mno";
        mpp['7']="pqrs";
        mpp['8']="tuv";
        mpp['9']="wxyz";
        string prev;
        fun(digits,0,n,prev,mpp,res);
        return res;
    }
};