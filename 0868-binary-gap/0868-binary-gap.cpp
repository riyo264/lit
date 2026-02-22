class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        bitset<32> bin(n);
        string s = bin.to_string();
        bool flag = false;
        int dist = 0;
        int j = 0;
        while(s[j] == '0') {
            j++;
        }
        for(int i = j; i < s.size(); i++)
        {
            if(flag == false && s[i] == '1') {
                flag = true;
            }
            else if(flag && s[i] == '1') {
                ans = max(dist, ans);
                dist = 0;
            }

            dist++;
        }
        return ans;
    }
};