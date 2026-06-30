class Solution {
public:
    int numberOfSubstrings(string s) {
        int left=0;
        int right=0;
        int n=s.size();
        int count=0;
        vector<int> map(3,0);
        while(right<n){
            map[s[right]-'a']++;
            while(map[0]>0 && map[1]>0 && map[2]>0){
                count+=n-right;
                map[s[left]-'a']--;
                left++;
            }
            right++;
        }
        return count;
    }
};