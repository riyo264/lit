class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        if(n < 3) {
            return 0;
        }
        int l = 0, h = 2;
        int cnt = 0;
        while(h < n) {
            if(s[l] != s[h] && s[l+1] != s[l] && s[l+1] != s[h]) {
                cnt++;
            }
            l++;
            h++;
        }
        return cnt;
    }
};