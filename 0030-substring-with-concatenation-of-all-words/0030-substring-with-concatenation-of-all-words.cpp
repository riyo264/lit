class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int m = words.size();
        int k = words[0].size();
        int limit = m*k;
        vector<int> ans;
        unordered_map<string, int> mpp1;
        for(string it : words) 
        {
            mpp1[it]++;
        }
        for(int offset = 0; offset < k; offset++) {
            int i = offset;
            int j = i+limit-1;
            while(j < n) {
                unordered_map<string, int> mpp;
                string t = "";
                for(int a = i; a <= j+1; a++)
                {
                    if(t.size() == k) {
                        mpp[t]++;
                        if(a < n) {
                            t = s[a];
                        }
                    }
                    else {
                        t += s[a];
                    }
                }
                if(mpp == mpp1) {
                    ans.push_back(i);
                }
                i += k;
                j += k;
            }
        }
        return ans;
    }
};