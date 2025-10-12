class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        if(citations[n-1] == 0) {
            return 0;
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(citations[i] >= (n-i)) {
                ans = n-i;
                break;
            }
        }
        return ans;
    }
};