class Solution {
public:
    void solve(int i, string& digits, unordered_map<char, string>& mpp, string s, vector<string>& ans) {
        int n = digits.size();
        if(i == n) {
            ans.push_back(s);
            return;
        }
        for(int k = 0; k < mpp[digits[i]].size(); k++)
        {
            s.push_back(mpp[digits[i]][k]);
            solve(i+1, digits, mpp, s, ans);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mpp;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";
        vector<string> ans;
        string s = "";
        solve(0, digits, mpp, s, ans);
        return ans;
    }
};