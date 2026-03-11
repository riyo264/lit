class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) {
            return 1;
        }
        bitset<32> bin(n);
        bool flag = false;
        string s = bin.to_string();
        for(int i = 0; i < 32; i++) 
        {
            if(!flag && s[i] == '0') {
                continue;
            }
            else if(!flag && s[i] == '1') {
                flag = true;
                s[i] = '0';
            }
            else if(flag && s[i] == '0') {
                s[i] = '1';
            }
            else {
                s[i] = '0';
            }
        }
        int j = 0;
        int ans = 0;
        int i = 31;
        while(i > -1) {
            if(s[i] == '1') {
                ans += pow(2, j);
            }
            i--;
            j++;
        }
        return ans;
    }
};