class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int m = words.size();
        int k = words[0].size();
        int limit = m*k;
        int i = 0, j = limit-1;
        vector<int> ans;
        unordered_map<string, int> mpp1;
        for(string it : words) 
        {
            mpp1[it]++;
        }
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
            i++;
            j++;
        }
        return ans;
    }
};