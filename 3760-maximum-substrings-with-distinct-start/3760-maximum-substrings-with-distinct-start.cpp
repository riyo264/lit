class Solution {
public:
    int maxDistinct(string s) {
        set<char> mset;
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            mset.insert(s[i]);
        }
        return mset.size();
    }
};