class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        if(target == 1) {
            return 0;
        }
        int ans = 0;
        // if(target >= 999999996 && maxDoubles == 0) {
        //     return target-1;
        // }
        while(maxDoubles > 0) 
        {
            if(target % 2 != 0) {
                target--;
            }
            else {
                if(maxDoubles != 0) {
                    target /= 2;
                    maxDoubles--;
                }
                else {
                    target--;
                }
            }
            ans++;
            if(target == 1) {
                break;
            }
        }
        if(target != 1) {
            ans += (target -1);
        }
        return ans;
    }
};