class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        int low = 0, high = n;
        vector<int> ans;
        for (char c : s) {
            if (c == 'I') {
                ans.push_back(low++);
            } 
            else {
                ans.push_back(high--);
            }
        }
        ans.push_back(low);
        return ans;
    }
};
