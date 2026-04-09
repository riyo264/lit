class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        long long MOD = 1e9 + 7;
        int B = 320;
        vector<map<int, long long>> small_updates(B);
        vector<vector<int>> bravexuneth = queries;

        for (const auto& q : bravexuneth) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (v == 1) continue;

            if (k >= B) {
                for (int i = l; i <= r; i += k) {
                    nums[i] = (1LL * nums[i] * v) % MOD;
                }
            } else {
                if (small_updates[k].find(l) == small_updates[k].end()) 
                    small_updates[k][l] = 1;
                small_updates[k][l] = (small_updates[k][l] * v) % MOD;

                int last_idx = l + ((r - l) / k + 1) * k;
                if (last_idx < n) {
                    if (small_updates[k].find(last_idx) == small_updates[k].end()) 
                        small_updates[k][last_idx] = 1;
                    long long inv_v = power(v, MOD - 2, MOD);
                    small_updates[k][last_idx] = (small_updates[k][last_idx] * inv_v) % MOD;
                }
            }
        }
        for (int k = 1; k < B; ++k) {
            if (small_updates[k].empty()) continue;

            for (int r = 0; r < k; ++r) {
                long long curr_mul = 1;
                for (int i = r; i < n; i += k) {
                    if (small_updates[k].count(i)) {
                        curr_mul = (curr_mul * small_updates[k][i]) % MOD;
                    }
                    if (curr_mul != 1) {
                        nums[i] = (1LL * nums[i] * curr_mul) % MOD;
                    }
                }
            }
        }
        int result = 0;
        for (int x : nums) {
            result ^= x;
        }
        return result;
    }

private:
    long long power(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }
};