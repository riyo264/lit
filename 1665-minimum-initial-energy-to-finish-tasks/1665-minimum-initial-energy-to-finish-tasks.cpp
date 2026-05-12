class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int min_nrg = 0;
        for(auto x : tasks) {
            min_nrg += x[0];
        }
        int check = min_nrg;
        sort(tasks.begin(), tasks.end(), [](auto& a, auto& b) {
            int i = abs(a[0]-a[1]);
            int j = abs(b[0]-b[1]);
            if(i == j) {
                return a[0] < b[0];
            }
            return i > j;
        });
        for(auto x : tasks) {
            if(check == 0) {
                min_nrg += x[1];
                continue;
            }
            if(check >= x[1]) {
                check -= x[0];
            }
            else {
                int d = x[1] - check;
                min_nrg += d;
                check += d;
                check -= x[0];
            }
        }
        return min_nrg;
    }
};