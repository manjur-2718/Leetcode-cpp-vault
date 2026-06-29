struct cmp{
    bool operator()(pair<int,char> &a,pair<int,char> &b){
        if(a.first!=b.first){
            return a.first<b.first;
        }
        return a.second>b.second;
    }
};
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mpp;
        for(char c:tasks){
            mpp[c]++;
        }
        priority_queue<pair<int,char>,vector<pair<int,char>>,cmp> pq;
        unordered_map<char,int> check;
        for(auto it:mpp){
            pq.push({it.second,it.first});
        }

        int interval=0;
        while(!pq.empty()){
            int cycleLength=n+1;
            int taskExecuted=0;
            vector<pair<int,char>> executed;
            while(cycleLength>0 && !pq.empty()){
                pair<int,char> p=pq.top();
                pq.pop();
                if(p.first>1){
                    p.first--;
                    executed.push_back(p);
                }
                taskExecuted++;
                cycleLength--;

            }
            
            for(auto &p:executed){
                pq.push(p);
            }
            if(!pq.empty()){
                interval+=(n+1);
            }
            else{
                interval+=taskExecuted;
            }
            
            
        }
        return interval;
    }
};