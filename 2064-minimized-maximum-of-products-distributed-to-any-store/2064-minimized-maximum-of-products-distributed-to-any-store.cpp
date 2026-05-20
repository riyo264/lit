class Solution {
public:
    bool ValidDist(int n, vector<int>& quantities, int mid) {
        int stores = 0;
        for(int q : quantities) {
            stores += ceil((double)q/(double)mid); 
        }
        return stores <= n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        int l = 1, h = -1;
        for(int i = 0; i < m; i++) {
            h = max(h, quantities[i]);
        }
        int ans = 0;
        while(l <= h) {
            int mid = l + (h-l)/2;
            if(ValidDist(n, quantities, mid)) {
                ans = mid;
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};