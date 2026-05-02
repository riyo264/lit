class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            int m = i;
            bool flag = false;
            while(m > 0) {
                int r = m % 10;
                if(r == 3 || r == 4 || r == 7) {
                    flag = false;
                    break;
                }
                if(r == 2 || r == 5 || r == 6 || r == 9) {
                    flag = true;
                }
                m /= 10;
            }
            if(flag) {
                ans++;
            }
        }
        return ans;
    }
};