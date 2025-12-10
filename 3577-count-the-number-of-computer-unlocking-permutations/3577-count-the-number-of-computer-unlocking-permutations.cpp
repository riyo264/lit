class Solution {
public:
    const int MOD = 1e9 + 7;
    long long permutations(int n) {
        if (n == 0)
            return 1;
        long long res = 1;
        for (int i = 2; i <= n; i++) 
        {
            res *= i;
            res = (res % MOD);
        }
        return res % MOD;
    }
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        int mini = complexity[0];
        for(int i = 1; i < n; i++)
        {
            if(complexity[i] <= mini) {
                return 0;
            }
            // else if(complexity[i-1] == complexity[i]) {
            //     return 0;
            // }
        }
        long long ans = permutations(n-1);
        return ans % MOD;
    }
};