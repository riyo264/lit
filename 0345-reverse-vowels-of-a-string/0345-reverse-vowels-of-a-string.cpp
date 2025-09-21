class Solution {
public:
    string reverseVowels(string s) {
        string ans;
        int j = s.size()-1;
        for(int i = 0; i < s.size(); i++) 
        {
            if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' && s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U') {
                ans.push_back(s[i]);
            }
            else {
                while(j > -1) 
                {
                   if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' || s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U') {
                        ans.push_back(s[j]);
                        j--;
                        break;
                    } 
                    j--;
                }
            }
        }
        return ans;
    }
};