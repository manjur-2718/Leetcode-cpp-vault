struct cmp{
    bool operator()(pair<int,char> &a, pair<int,char> &b){
        if(a.first!=b.first){
            return a.first<b.first;
        }
        return a.second>b.second;
    }
};
class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>,vector<pair<int,char>>,cmp> pq;
        unordered_map<char,int> mpp;
        for(char c:s){
            mpp[c]++;
        }
        for(auto it:mpp){
            pq.push({it.second,it.first});
        }
        string res="";
        pair<int,char> prev={-1,'#'};
        while(!pq.empty()){
            pair<int,char> curr=pq.top();
            pq.pop();
            res.push_back(curr.second);
            curr.first--;
            if(prev.first>0){
                pq.push(prev);
            }
            prev=curr;
        }
        if(res.size()==s.size()){
            return res;
        }
        return "";
    }
};