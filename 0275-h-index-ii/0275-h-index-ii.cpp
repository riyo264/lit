class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0;
        int h = n-1;
        int ans = 0;
        if(n == 1) {
            if(citations[0] == 0) {
                return 0;
            }
            return 1;
        }
        while(l <= h) 
        {
            int mid = (l+h)/2;
            if(citations[mid] < n-mid) {
                l = mid + 1;
                ans = max(ans, citations[mid]);
            }
            else if(citations[mid] > n-mid)
            {
                h = mid - 1;
                ans = max(ans, n-mid);
            }
            else {
                ans = citations[mid];
                break;
            }
        }
        return ans;
    }
};