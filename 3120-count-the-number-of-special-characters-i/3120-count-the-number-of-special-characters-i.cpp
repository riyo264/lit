class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0;
        int n = word.size();
        unordered_map<char, int> mpp;
        for(int i = 0; i < n; i++)
        {
            mpp[word[i]]++;
        }
        for(char it = 'a'; it <= 'z'; it++) {
            char c = toupper(it);
            if(mpp[it] >= 1 && mpp[c] >= 1) {
                ans++;
            }
        }
        return ans;
    }
};