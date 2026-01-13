class Solution {
public:
    int check(vector<vector<int>>& squares, double y) {
        double above = 0;
        double below = 0;
        for(auto& x : squares) {
            if(y >= x[1]+x[2]) {
                below += ((double)x[2] * (double)x[2]);
            }
            else if(y <= x[1]) {
                above += ((double)x[2] * (double)x[2]);
            }
            else {
               below += x[2] * (y - x[1]);
               above += x[2] * ((x[1] + x[2]) - y);
            }
        }
        const double EPS = 1e-7;
        if (fabs(above - below) < EPS) return 0;
        if (above > below) return 1;
        return -1;
    }
    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();
        int maxy = INT_MIN;
        for(auto& x : squares) {
            maxy = max(maxy, x[1]+x[2]);
        }
        double low = 0;
        double high = maxy;
        for (int iter = 0; iter < 80; iter++) {
            double mid = (low + high) / 2;
            int res = check(squares, mid);
            if (res == 1) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return (low + high) / 2;
    }
};