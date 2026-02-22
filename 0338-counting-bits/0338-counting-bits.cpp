class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i = 0; i <= n; i++)
        {
            bitset<32> bin(i);
            string s = bin.to_string();
            int cnt = 0;
            for(int j = 0; j < s.size(); j++) 
            {
                if(s[j] == '1') {
                    cnt++;
                }
            }
            ans[i] = cnt;
        }
        return ans;
    }
};