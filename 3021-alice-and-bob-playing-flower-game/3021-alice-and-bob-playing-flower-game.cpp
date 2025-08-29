class Solution {
public:
    long long flowerGame(int n, int m) {
        long long odd1, odd2, even1, even2;
        if(n%2 != 0) {
            odd1 = n/2 + 1;
        }
        else {
            odd1 = n/2;
        }
        even1 = n - odd1;
        if(m%2 != 0) {
            odd2 = m/2 + 1;
        }
        else {
            odd2 = m/2;
        }
        even2 = m - odd2;
        long long x = odd1 * even2;
        long long y = odd2 * even1;
        return x+y;
    }
};