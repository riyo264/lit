class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> mpp;
        unordered_map<char, int> occ;
        int n = word.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(word[i] <= 'Z' && mpp[word[i]] == 0) {
                occ[word[i]] = i;
                mpp[word[i]]++;
            }
        }
        for(int i = n-1; i > -1; i--) {
            if(word[i] >= 'a' && mpp[word[i]] == 0) {
                occ[word[i]] = i;
                mpp[word[i]]++;
            }
        }
        for(char c = 'a'; c <= 'z'; c++)
        {
            if(occ.count(c) && occ.count(toupper(c)) && occ[c] < occ[toupper(c)]) {
                ans++;
            }
        }
        return ans;
    }
};