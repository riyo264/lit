class Solution {
public:
    bool hasAlternatingBits(int n) {
        int last = -1;
        while(n != 0) {
            int LSB = n % 2;
            if(n == 1) {
                LSB = 1;
            }
            if(last == -1) {
                last = LSB;
            }
            else if(last == 0 && LSB == 0) {
                return false;
            }
            else if(last == 1 && LSB == 1) {
                return false;
            }
            last = LSB;
            n = n/2;
        }
        return true; 
    }
};