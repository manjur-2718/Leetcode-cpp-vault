class Solution {
    unordered_map<string, int> mpp;
    vector<vector<string>> ans;
    string b;

private:
    void dfs(string word, vector<string>& seq) {
        if (b == word) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end()); // re-reverse it so that while going back the
                                            // right word gets popped back
            return;
        }
        int sz = word.size();
        int steps = mpp[word];
        for (int i = 0; i < sz; i++) {
            char original = word[i];
            for (char c = 'a'; c <= 'z'; c++) {
                word[i] = c;
                if (mpp.find(word) != mpp.end() && mpp[word] + 1 == steps) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        b = beginWord;
        int sz = beginWord.size();
        mpp[beginWord] = 1;
        st.erase(beginWord);
        while (!q.empty()) {
            string word = q.front();
            int step = mpp[word];
            q.pop();
            if(word == endWord) break;
            for (int i = 0; i < sz; i++) {
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if (st.find(word) != st.end()) {
                        q.push(word);
                        mpp[word] = step + 1;
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }

        if (mpp.find(endWord) != mpp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return ans;
    }
};