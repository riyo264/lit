class Solution {
private:
    long long modInverse(long long a, long long mod) {
        long long res = 1, exp = mod - 2;
        while (exp > 0) {
            if (exp & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            exp >>= 1;
        }
        return res;
    }
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        long long MOD = 1e9 + 7;
        vector<int> powers;
        vector<int> result;
        int val = 1;
        while(n > 0) 
        {
            if((n & 1) == 1) {
                powers.push_back(val);
            }
            val = val * 2;
            n = n >> 1;
        }
        int m = powers.size();
        vector<long long> prefix(m, 1);
        prefix[0] = powers[0] % MOD;
        for (int i = 1; i < m; i++) {
            prefix[i] = (prefix[i - 1] * powers[i]) % MOD;
        }
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            long long prod = prefix[r];
            if (l > 0) prod = (prod * modInverse(prefix[l - 1], MOD)) % MOD;
            result.push_back((int)prod);
        }
        return result;
    }
};