class Solution {
    const long long MOD = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

public:
    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;  
        long long oddCount  = n / 2;        

        long long ans = (modPow(5, evenCount) * modPow(4, oddCount)) % MOD;
        return (int) ans;
    }
};
