class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int n = paragraph.size();
        unordered_map<string, int> mpp;
        string s = "";
        for(int i = 0; i < n; i++)
        {
            if(isalpha(paragraph[i])) {
                s.push_back(tolower(paragraph[i]));
            }
            else if(!isalpha(paragraph[i])) {
                if(s.size() > 0) {
                    mpp[s]++;
                }
                s = "";
            }
            if(i == n-1 && s.size() > 0) {
                mpp[s]++;
            }
        }
        for(auto x : banned) mpp[x] = 0;
        string ans = "";
        int maxi = 0;
        for(auto it : mpp) {
            if(it.second > maxi) {
                ans = it.first;
                maxi = it.second;
            }
        }
        return ans;
    }
};