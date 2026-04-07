class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int m = words.size();
        int k = words[0].size();
        unordered_map<string, int> mpp1;
        for(string it : words) {
            mpp1[it]++;
        }
        vector<int> ans;
        for(int offset = 0; offset < k; offset++) {
            int i = offset;
            int count = 0;
            unordered_map<string, int> mpp;
            for(int j = offset; j + k <= n; j += k) {
                string word = s.substr(j, k);
                if(mpp1.count(word)) {
                    mpp[word]++;
                    count++;
                    while(mpp[word] > mpp1[word]) {
                        string leftWord = s.substr(i, k);
                        mpp[leftWord]--;
                        i += k;
                        count--;
                    }
                    if(count == m) {
                        ans.push_back(i);
                    }
                }
                else {
                    mpp.clear();
                    count = 0;
                    i = j + k;
                }
            }
        }
        return ans;
    }
};