class Solution {
unordered_map<string, int> mpp;
vector<vector<string>> ans;
string begin;
private:
    void dfs(string word, vector<string>& seq) {
        if(word == begin) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int n = word.size();
        int steps = mpp[word];
        for(int i = 0; i < n; i++)
            {
                char original = word[i];
                for(char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c;
                    if(mpp.find(word) != mpp.end() && mpp[word]+1 == steps) {
                        seq.push_back(word);
                        dfs(word, seq);
                        seq.pop_back();
                    }
                }
                word[i] = original;
            }
        }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

/* CP APPROACH */
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> Q;
        Q.push(beginWord);
        begin = beginWord;
        mpp[beginWord] = 1;
        st.erase(beginWord);
        int n = beginWord.size();
        while(!Q.empty())
        {
            string word = Q.front();
            Q.pop();
            int steps = mpp[word];
            if(word == endWord) break;
            for(int i = 0; i < n; i++)
            {
                char original = word[i];
                for(char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c;
                    if(st.count(word)) {
                        Q.push(word);
                        st.erase(word);
                        mpp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }
        if(mpp.find(endWord) != mpp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return ans; 


/*INTERVIEW APPROACH*/  
        // vector<vector<string>> ans;
        // unordered_set<string> st(wordList.begin(), wordList.end());
        // queue<vector<string>> Q;
        // Q.push({beginWord});
        // vector<string> used;
        // used.push_back(beginWord);
        // int level = 0;
        // while(!Q.empty())
        // {
        //     vector<string> temp = Q.front();
        //     Q.pop();
        //     if(temp.size() > level) {
        //         level++;
        //         for(auto it : used)
        //         {
        //             st.erase(it);
        //         }
        //     }
        //     string word = temp.back();

        //     if(word == endWord) {
        //         if(ans.size() == 0) {
        //             ans.push_back(temp);
        //         }
        //         else if(ans[0].size() == temp.size()) {
        //             ans.push_back(temp);
        //         }
        //     }
        //     for(int i = 0; i < word.size(); i++)
        //     {
        //         char original = word[i]; 
        //         for(char c = 'a'; c <= 'z'; c++)
        //         {
        //             word[i] = c;
        //             if(st.count(word) > 0) {
        //                 temp.push_back(word);
        //                 Q.push(temp);
        //                 used.push_back(word);
        //                 temp.pop_back();
        //             }
        //         }
        //         word[i] = original;
        //     }
        // }
        // return ans;
    }
};
