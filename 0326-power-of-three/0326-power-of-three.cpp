class Solution {
public:
    bool isPowerOfThree(int n) {
        int check = 0;
        if(n == 0) {
            return false;
        }
        else if(n == -1)
        {
            return false;
        }
        while(n != 1) 
        {
            if(n%3 != 0) {
                return false;
            }
            n = n/3;
        }
        return true;
    }
};