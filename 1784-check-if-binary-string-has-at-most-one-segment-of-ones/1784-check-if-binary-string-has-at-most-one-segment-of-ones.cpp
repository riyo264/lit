class Solution {
public:
    bool checkOnesSegment(string s) {
        int i = 0;
        bool ans = true;
        bool zero = false;
        while(i < s.size()) 
        {
            if(s[i] == '0') {
                zero = true;
            }
            else if(zero) {
                ans = false;
                break;
            }
            i++;
        }
        return ans;
    }
};