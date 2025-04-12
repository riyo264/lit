class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        int a = -1, b = -1, c = -1;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i]=='a')
            {
                a = max(i, a);
            }
            else if(s[i] == 'b')
            {
                b = max(i, b);
            }
            else if(s[i] == 'c')
            {
                c = max(i, c);
            }

            if(a >= 0 && b >= 0 && c >= 0){
                cnt = cnt + min(min(a, b), c) + 1;
            }
        }
        return cnt;
    }
};