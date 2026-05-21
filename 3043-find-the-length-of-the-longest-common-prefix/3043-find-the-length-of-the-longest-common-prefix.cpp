class Solution {
public:
    int longestCommonPrefix(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<string> st;
        for(int x : nums1) {
            string s = to_string(x);
            string t;
            for(int i = 0; i < s.size(); i++)
            {
                t.push_back(s[i]);
                st.insert(t);
            }
        }

        int len = 0;
        for(int x : nums2) {
            string p = to_string(x);
            string q;
            for(int i = 0; i < p.size(); i++)
            {
                q.push_back(p[i]);
                if(st.count(q)) {
                    len = max(len, i+1);
                }
            }
        }

        return len;
    }
};