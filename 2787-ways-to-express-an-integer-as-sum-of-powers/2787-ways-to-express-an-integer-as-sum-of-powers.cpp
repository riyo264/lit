class Solution {
public:
    int numberOfWays(int n, int x) {
    const int MOD = 1e9 + 7;
    vector<int> powers;
    for (int k = 1; ; k++) {
        long long p = 1;
        for (int i = 0; i < x; i++) p *= k;
        if (p > n) break;
        powers.push_back((int)p);
    }

    vector<int> dp(n + 1, 0);
    dp[0] = 1; 

    for (int p : powers) {
        for (int s = n; s >= p; s--) {
            dp[s] = (dp[s] + dp[s - p]) % MOD;
        }
    }

    return dp[n];
    }
};