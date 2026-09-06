class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> mpp(wordList.begin(),wordList.end());
        mpp.erase(beginWord);
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word==endWord) return steps;
            for(int i=0; i<word.size(); i++){
                char original = word[i];
                for(char change='a'; change<='z'; change++){
                    word[i] = change;
                    if(mpp.find(word)!=mpp.end()){
                        q.push({word,steps+1});
                        mpp.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};