class Solution {
public:
    string reverseWords(string s) {
        int i=s.size()-1;
        string res;
        while(i>=0){
            while(i>=0 && s[i]==' '){
                i--;
            } 

            int end=i;
            if(i<0) break;
            while(i>=0 && s[i]!=' '){
                i--;
            } 
            string temp=s.substr(i+1,end-i);

            if(!res.empty()){
            res+=" ";
            }
            res+=temp;
        }
        return res;
    }
    
};