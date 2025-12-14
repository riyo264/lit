class Solution {
public:
    // int solve(string& s, int i, int total_s, int& taken_s, int& ways) {

    //     int left_s = (total_s - taken_s);
    //     if(left_s == taken_s) {
    //         if(s[i] == 'S') {
    //             ways = 1 + solve(s, i+1, total_s, taken_s+1, ways)
    //         }
    //     }
    // }
    const int MOD = 1e9 + 7;
    int numberOfWays(string corridor) {
        int n = corridor.size();
        int S_cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(corridor[i] == 'S') {
                S_cnt++;
            }
        }
        if(S_cnt % 2 != 0 || S_cnt == 0) {
            return 0;
        }
        long long ans = 1;
        int p = 0;
        int c = 0;
        for(int i = 0; i < n; i++)
        {
            if(S_cnt == c) {
                break;
            }
            if(corridor[i] == 'S') {
                c++;
                if(c % 2 != 0 && c != 1) {
                    ans = (ans * (p+1)) % MOD;
                    p = 0;
                }
            }
            else if(corridor[i] == 'P') {
                if(c % 2 == 0 && c != 0) {
                    p++;
                }
                // else {
                //     p = 0;
                // }
            }
        }
        return (int)ans % MOD;
    }
};