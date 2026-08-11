class Solution {
public:
    struct cmp{
        bool operator()(pair<int,char> &p1,pair<int,char> &p2){
            if(p1.first!=p2.first){
                return p1.first<p2.first;
            }
            return p1.second>p2.second;
        }
    };
    string frequencySort(string s) {
        unordered_map<char,int> mpp;
        for(char c:s){
            mpp[c]++;
        }
        priority_queue<pair<int,char>,vector<pair<int,char>>,cmp> pq;
        for(auto it:mpp){
            pq.push({it.second,it.first});
        }
        string res;

        while(!pq.empty()){
            pair<int,char> curr = pq.top();
            pq.pop();
            int n= curr.first;
            for(int i=0; i<n; i++){
                res+=curr.second;
            }
        }
        return res;
    }
};