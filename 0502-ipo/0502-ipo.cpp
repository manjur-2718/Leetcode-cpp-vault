class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>> choice;
        for(int i=0; i<n; i++){
            choice.push_back({capital[i],profits[i]});
        }
        sort(choice.begin(),choice.end());
        int idx=0;
        priority_queue<int> pq;
        while(k--){
            while(idx<n){
                if(choice[idx].first>w) break;
                pq.push(choice[idx].second);
                idx++;
            }
            if(pq.empty()) return w;
            w+=pq.top();
            pq.pop();

        }
        return w;
    }
};