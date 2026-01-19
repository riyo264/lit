class Solution {
public:
    bool isValid(vector<int>& weights, int days, int m) {
        int n = weights.size();
        int cap = 0;
        int cnt = 1;
        for (int w : weights) {
            if (cap + w > m) {
                cnt++;
                cap = w;
            } else {
                cap += w;
            }
        }
        if(cnt <= days) {
            return true;
        }
        else {
            return false;
        }
    }
    int shipWithinDays(vector<int>& weights, int days) {
        long long tw = 0;
        int n = weights.size();
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            maxi = max(maxi, weights[i]);
            tw += weights[i];
        }
        long long l = maxi;
        long long h = tw;
        int ans = h;
        while(l <= h) 
        {
            long long m = l + (h-l)/2;
            if(isValid(weights, days, m)) {
                ans = m;
                h = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ans;
    }
};