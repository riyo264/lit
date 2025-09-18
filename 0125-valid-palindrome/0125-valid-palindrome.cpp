class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string back;
        for(int i = s.size()-1; i > -1; i--)
        {
            if(isalnum(s[i])) {
                back.push_back(s[i]);
            }
        }
        int left = 0, right = back.size() - 1;
        while (left < right) {
            if (back[left] != back[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};