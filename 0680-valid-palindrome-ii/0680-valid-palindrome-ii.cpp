class Solution {
public:
    bool Pali(string s, int i, int j) {
        while(i < j) {
            if(s[i] == s[j]) {
                i++;
                j--;
            }
            else {
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        int i = 0;
        int j = n-1;
        while(i < j) 
        {
            if(s[i] == s[j]) {
                i++;
                j--;
            }
            else {
                if(!Pali(s, i, j-1) && !Pali(s, i+1, j)) {
                    return false;
                }
                else {
                    return true;
                }
            }
        }
        return true;
    }
};