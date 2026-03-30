class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        map<char, int> mpp1, mpp2;
        for(int i = 0; i < n; i += 2) {
            mpp1[s1[i]]++;
            mpp1[s2[i]]--;
        }
        for(auto x : mpp1) 
        {
            if(x.second != 0) {
                return false;
            }
        }
        for(int i = 1; i < n; i += 2) {
            mpp2[s1[i]]++;
            mpp2[s2[i]]--;
        }
        for(auto x : mpp2) 
        {
            if(x.second != 0) {
                return false;
            }
        }
        return true;
    }
};