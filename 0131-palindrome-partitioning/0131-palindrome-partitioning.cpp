class Solution {
public:
    void solve(string s, int i, vector<vector<string>>& ans, vector<string>& pali) {
        if(i == s.size()) {
            ans.push_back(pali);
            return;
        }
        for(int j = i+1; j <= s.size(); j++) {
            if(isPali(s, i, j-1)) {
                pali.push_back(s.substr(i, j-i));
                solve(s, j, ans, pali);
                pali.pop_back();
            }
        }
    }
    bool isPali(string s, int l, int r) {
        while(l <= r) {
            if(s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> pali;
        solve(s, 0, ans, pali);
        return ans;
    }
};