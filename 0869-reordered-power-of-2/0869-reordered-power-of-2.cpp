class Solution {
public:
    bool reorderedPowerOf2(int n) {
        if(n == 1) {
            return true;
        }
        string s = to_string(n);
        sort(s.begin(), s.end());
        long long pow = 1;
        for(int i = 0; i < 31; i++)
        {
            pow = pow * 2;
            string t = to_string(pow);
            sort(t.begin(), t.end());
            if(s == t) {
                return true;
            }
        }
        return false;
    }
};