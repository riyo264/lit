class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l = 1;
        long long h = num;
        while(l <= h) 
        {
            long long mid = h - ((h-l)/2);
            if(mid*mid > num) {
                h = mid - 1;
            }
            else if(mid*mid < num) {
                l = mid + 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};