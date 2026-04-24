class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = indices.size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[indices[i]].push_back(i);
        }
        string ans = "";
        for(int i = 0; i < s.size(); ) {
            if(mp.count(i)) {
                bool replaced = false;
                vector<int> idx = mp[i];
                for(int j = 0; j < idx.size(); j++) {
                    string &src = sources[idx[j]];
                    if(i + src.size() <= s.size() && s.substr(i, src.size()) == src) {
                        ans += targets[idx[j]];
                        i += src.size();
                        replaced = true;
                        break;
                    }
                }
                if(replaced) continue;
            }
            ans += s[i];
            i++;
        }
        return ans;
    }
};