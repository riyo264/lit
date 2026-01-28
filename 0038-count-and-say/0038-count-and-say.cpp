class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 2; i <= n; i++)
        {
            string res = "";
            int freq = 0;
            for(int j = 0; j < ans.size(); j++) {
                if(j > 0 && ans[j] != ans[j-1]) {
                    int t = freq;
                    freq = 0;
                    string s = to_string(t);
                    res += s;
                    res.push_back(ans[j-1]);
                }
                freq++;
                if(j == ans.size()-1) {
                    int x = freq;
                    string y = to_string(x);
                    res += y;
                    res.push_back(ans[j]);
                }
            }
            ans = res;
        }
        return ans;
    }
};