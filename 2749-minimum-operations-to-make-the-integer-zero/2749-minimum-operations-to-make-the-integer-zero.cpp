class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int i = 1; i <= 60; i++)
        {
            long long val = 1LL * num1 - 1LL * i * num2;
            if(val < 0) continue;
            if(__builtin_popcountll(val) <= i && val >= i) {
                return i;
            }
        }
        return -1;
    }
};