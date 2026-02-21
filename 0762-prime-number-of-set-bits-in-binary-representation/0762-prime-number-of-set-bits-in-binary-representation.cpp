class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i = left; i <= right; i++) 
        {
            bitset<32> bin(i);
            string s = bin.to_string();
            int cnt = 0;
            for(int j = 0; j < 32; j++) 
            {
                if(s[j] == '1') {
                    cnt++;
                }
            }
            if(cnt == 2) {
                ans++;
                continue;
            }
            for(int k = 2; k < cnt; k++)
            {
                if(cnt % k == 0) {
                    break;
                }
                else if(k == cnt-1 && cnt % (cnt-1) != 0) {
                    ans++;
                }
            }
        }
        return ans;      
    }
};