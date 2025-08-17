class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> Q;
        Q.push({beginWord, 1});
        set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        while(!Q.empty())
        {
            string word = Q.front().first;
            int n = Q.front().second;
            Q.pop();
            if(word == endWord) {
                return n;
            }

            for(int i = 0; i < word.size(); i++)
            {
                char pres = word[i];
                for(char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c;
                    if(st.find(word) != st.end()) {
                        st.erase(word);
                        Q.push({word, n+1});
                    }
                }
                word[i] = pres;
            }
        }
        return 0;
    }
};