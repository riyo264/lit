class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        string ans(n + m - 1, '?');

        for(int i = 0; i < n; i++) {
            if(str1[i] == 'T') {
                for(int j = 0; j < m; j++) {
                    if(ans[i + j] == '?' || ans[i + j] == str2[j]) {
                        ans[i + j] = str2[j];
                    } else {
                        return "";
                    }
                }
            }
        }

        for(int i = 0; i < ans.size(); i++) {
            if(ans[i] == '?') {
                for(char c = 'a'; c <= 'z'; c++) {
                    ans[i] = c;
                    bool ok = true;
                    for(int j = max(0, i - m + 1); j <= min(i, n - 1); j++) {
                        if(str1[j] == 'F') {
                            bool match = true;
                            for(int k = 0; k < m; k++) {
                                if(ans[j + k] == '?' || ans[j + k] != str2[k]) {
                                    match = false;
                                    break;
                                }
                            }
                            if(match) ok = false;
                        }
                    }
                    if(ok) break;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            if(str1[i] == 'F') {
                bool match = true;
                for(int j = 0; j < m; j++) {
                    if(ans[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }
                if(match) return "";
            }
        }

        return ans;
    }
};