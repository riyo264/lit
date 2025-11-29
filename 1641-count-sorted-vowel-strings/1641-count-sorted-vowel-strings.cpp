class Solution {
public:
    int countVowelStrings(int n) {
        int m = 5;
        int ans = 1;
        for(int i = 1; i <= m-1; i++) 
        {
            ans = ans * (n + i) / i;
        }
        return ans;
    }
};