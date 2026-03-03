class Solution {
public:
    char findKthBit(int n, int k) {
        vector<int> s;
        s.push_back(0);
        while(n--)
        {
            vector<int> inv(s.size());
            for(int i = 0; i < s.size(); i++)
            {
                inv[i] = (s[i])^1;
            }
            reverse(inv.begin(), inv.end());
            s.push_back(1);
            for(int i = 0; i < inv.size(); i++)
            {
                s.push_back(inv[i]);
            }
        }
        if(s[k-1] == 1) {
            return '1';
        }
        return '0';
    }
};