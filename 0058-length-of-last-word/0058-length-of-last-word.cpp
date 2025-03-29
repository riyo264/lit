class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int temp = n-1;
        int ans = 0;
        int spcnt = 0;
        stack <char> st;
        for(int i=n-1; i>-1; i--)
        {
            if(s[i] == ' ' && st.empty() == 1)
            {
                temp--;
                spcnt++;
                continue;
            }
            else if(s[i] == ' ' && st.empty() == 0)
            {
                ans = temp - i;
                break;
            }
            else if(i == 0 && s[i] != ' ')
            {
                ans = n - spcnt;  
            }
            else if(s[i] != ' ')
            {
                st.push(s[i]);
            }
        }
        return ans;
    }
};