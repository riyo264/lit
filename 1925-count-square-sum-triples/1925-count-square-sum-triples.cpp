class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                long long x = ((i*i) + (j*j)); 
                long long c = (long long) llround(sqrt((long double)x));
                if (c <= n && c * c == x) ++cnt;
            }
        }
        return cnt;
    }
};