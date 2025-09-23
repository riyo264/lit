class Solution {
public:
    int arrangeCoins(int n) {
        int rows = 0;
        long long coins = 1;
        long long j = 1;
        while(coins <= n) 
        {
            rows++;
            j++;
            coins += j;
        }
        return rows;
    }
};