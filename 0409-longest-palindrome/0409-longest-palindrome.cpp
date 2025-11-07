class Solution {
public:
    int longestPalindrome(string s) {
        int cnt = 0;
        unordered_map<char, int> mpp;
        for(int i = 0; i < s.size(); i++)
        {
            mpp[s[i]]++;
        }
        bool flag = false;
        // int check = 0;
        for(auto x : mpp) 
        {
            if(x.second % 2 == 0) {
                cnt += x.second;
            }
            else if(x.second % 2 != 0) {
                cnt += x.second - 1;
                flag = true;
            }
        }
        if(flag) cnt++;
        return cnt;
    }
};