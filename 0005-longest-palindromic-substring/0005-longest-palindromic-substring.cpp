class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==1) return s;
        int start=0; int maxLen=0;
        for(int i=0; i<n; i++){
            expandFromCenter(s,i,i,start,maxLen); // for odd length string
            expandFromCenter(s,i,i+1,start,maxLen); // for even length string
        }
        return s.substr(start,maxLen);
    }
private:
    void expandFromCenter(string& s, int left, int right, int &start, int &maxLen){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;
        }
        int currLen = right-left-1;
        if(currLen>maxLen){
            maxLen = currLen;
            start=left+1;
        }
    }
};