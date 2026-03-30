class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        map<char, int> mpp1, mpp2;
        for(int i = 0; i < n; i += 2) {
            mpp1[s1[i]]++;
            mpp2[s2[i]]++;
        }
        if(mpp1 != mpp2) {
            return false;
        }
        map<char, int> mpp_o, mppt;
        for(int i = 1; i < n; i += 2) {
            mpp_o[s1[i]]++;
            mppt[s2[i]]++;
        }
        if(mpp_o != mppt) {
            return false;
        }
        return true;
    }
};