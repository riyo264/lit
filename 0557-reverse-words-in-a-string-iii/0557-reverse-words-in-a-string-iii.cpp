class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int n = s.size();
        int i = 0;
        int j = 0;
        while(j < n) 
        {
            if(j == n-1 || s[j+1] == ' ') {
                int temp = j;
                while(i < j) 
                {
                    char a = s[i];
                    s[i] = s[j];
                    s[j] = a;
                    i++;
                    j--;
                }
                j = temp + 2;
                i = j;
                continue;
            }
            j++;
        }
        return s;
    }
};