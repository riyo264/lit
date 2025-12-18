class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        string s;
        int len = max(n, m);
        for(int i = 0; i < len; i++) {
            if(n-1 < i) {
                s.push_back(word2[i]);
            }
            else if(m-1 < i) {
                s.push_back(word1[i]);
            }
            else {
                s.push_back(word1[i]);
                s.push_back(word2[i]);
            }
        }
        return s;
    }
};