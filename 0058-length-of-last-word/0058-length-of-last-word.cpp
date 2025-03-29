class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i = n-1; i > -1; i--)
        {
            if(s[i]==' ' && (cnt != 0))
            {
                break;
            }
            else if(s[i]!=' ')
            {
                cnt++;
            }
        }
        return cnt;
    }
};