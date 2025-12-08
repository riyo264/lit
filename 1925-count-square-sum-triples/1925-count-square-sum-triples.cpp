class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            int target = i*i;
            int lo = 1;
            int hi = i - 1;
            while(lo < hi) 
            {
                int x = lo * lo + hi * hi;
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