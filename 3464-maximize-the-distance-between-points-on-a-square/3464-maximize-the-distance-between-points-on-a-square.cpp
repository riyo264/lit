class Solution {
public:
    bool isValid(long long dist, vector<long long>& clk, int k, long long perimeter) {
        int n = clk.size();
        for(int i = 0; i < n; i++) {
            int cnt = 1;
            long long last = clk[i];
            for(int j = i+1; j < n && cnt < k; j++) {
                if(clk[j] - last >= dist) {
                    cnt++;
                    last = clk[j];
                }
            }
            if(cnt == k && (perimeter - (last - clk[i])) >= dist) {
                return true;
            }
        }
        return false;
    }
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> clk;
        for(auto &p : points) {
            int x = p[0], y = p[1];
            if(x == 0) {
                clk.push_back(y);
            }
            else if(y == side) {
                clk.push_back(side + x);
            }
            else if(x == side) {
                clk.push_back(3LL * side - y);
            }
            else {
                clk.push_back(4LL * side - x);
            }
        }
        sort(clk.begin(), clk.end());
        long long peri = 4LL * side;

        int l = 1;
        int r = peri/k;
        while(l <= r) {
            int m = l + (r - l)/2;
            if(isValid(m, clk, k, peri)) {
                l = m+1;
            }
            else {
                r = m-1;
            }
        }
        return r;
    }
};