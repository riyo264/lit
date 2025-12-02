class Solution {
public:
    int MOD = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<long long, long long> countY;
    for (auto &p : points) {
        countY[p[1]]++;
    }
    vector<long long> H;
    H.reserve(countY.size());

    for (auto &it : countY) {
        long long k = it.second;
        if (k >= 2) {
            long long h = (k * (k - 1) / 2) % MOD;
            H.push_back(h);
        }
    }
    sort(H.begin(), H.end());  
    long long total = 0;
    long long prefix = 0;

    for (long long h : H) {
        total = (total + (h * prefix) % MOD) % MOD;
        prefix = (prefix + h) % MOD;
    }
    return total % MOD;
    }
};