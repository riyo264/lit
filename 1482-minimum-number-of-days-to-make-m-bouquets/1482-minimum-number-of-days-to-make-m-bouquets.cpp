class Solution {
    bool check(vector<int>& bloomDay, int m, int k, int days) {
        int n = bloomDay.size();
        int temp = k;
        for(int i = 0; i < n; i++) 
        {
            if(m==0) {
                break;
            }
            if(bloomDay[i] <= days) {
                temp--;
            }
            else if(bloomDay[i] > days) {
                temp = k;
            }
            if(temp == 0) {
                m--;
                temp = k;
            }
        }
        if(m==0) {
            return true;
        }
        return false;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        vector<int> BS = bloomDay;
        long long n = BS.size();
        long long flowers = ((long long)m*(long long)k);
        if(n < flowers) {
            return -1;
        }
        sort(BS.begin(), BS.end());
        int l = 0;
        int h = BS.size()-1;
        int ans = INT_MAX;
        while(l <= h) 
        {
            int mid = (l+h)/2;
            if(check(bloomDay, m, k, BS[mid]) == true) {
                ans = min(ans, BS[mid]);
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};