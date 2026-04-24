class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int l = 0;
        int r = 0;
        int a = 0;
        for(int i = 0; i < n; i++) {
            if(moves[i] == 'L') {
                l++;
            }
            else if(moves[i] == 'R') {
                r++;
            }
            else {
                a++;
            }
        } 
        // if(l == 0) {
        //     return a+r;
        // }
        // else if(r == 0) {
        //     return l+a;
        // }
        return abs(l-r) + a;
    }
};