class Solution {
public:
    int balancedStringSplit(string s) {
        int n = s.size();
        int ans = 0;
        bool flag = false;
        int l = 0;
        int r = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'R' && !flag) {
                ans++;
                r++;
                flag = true;
            }
            else if(s[i] == 'L' && !flag) {
                ans++;
                l++;
                flag = true;
            }
            else if(s[i] == 'R') {
                r++;
                if(l == r) {
                    l = 0;
                    r = 0;
                    flag = false;
                }
            }
            else if(s[i] == 'L') {
                l++;
                if(l == r) {
                    l = 0;
                    r = 0;
                    flag = false;
                }
            }
        }
        return ans;
    }
};