class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.size();
        int m = t.size();
        unordered_map<char, int> mpp;
        for(int i = 0; i < m; i++)
        {
            mpp[t[i]]++;
        }
        for(int i = 0; i < n; i++) 
        {
            mpp[s[i]]--;
        }
        for(auto it : mpp) {
            if(it.second == 1) {
                return it.first;
            }
        }
        return 'c';
    }
};