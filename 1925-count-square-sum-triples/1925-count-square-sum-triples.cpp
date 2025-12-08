class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            long long target = i*i;
            long long lo = 1;
            long long hi = target - 1;
            while(lo <= hi) 
            {
                long long x = ((1LL*lo*lo) + (1LL*hi*hi));
                if(x == target) {
                    cnt += 2;
                    lo++;
                    hi--;
                }
                else if(x < target) {
                    lo++;
                }
                else {
                    hi--;
                }
            }
        }
        return cnt;
    }
};