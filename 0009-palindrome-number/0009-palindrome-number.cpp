class Solution {
public:
    bool isPalindrome(int x) {
        long long temp = 0;
        int n = x;
        if(x < 0)
        {
            return false;
        }
        else
        {
            while(n > 0)
            {
                int mod = n % 10;
                n = n/10;
                temp = (temp * 10) + mod;
            }
            if(temp == x)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};