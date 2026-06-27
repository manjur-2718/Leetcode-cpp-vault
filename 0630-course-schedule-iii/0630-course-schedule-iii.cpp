class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n=courses.size();
        vector<pair<int,int>> choose;
        for(int i=0; i<n; i++){
            choose.push_back({courses[i][1],courses[i][0]});
        }
        sort(choose.begin(),choose.end());
        priority_queue<int> pq;
        int idx=0;
        int duration=0;
        int limit=0;
        while(idx<n){
            if(duration+choose[idx].second<=choose[idx].first){
                duration+=choose[idx].second;
                pq.push(choose[idx].second);
            }
            else if(!pq.empty() && pq.top()>choose[idx].second){
                duration=duration-pq.top()+choose[idx].second;
                pq.pop();
                pq.push(choose[idx].second);
            }
            idx++;
        }
        return pq.size();
    }
};