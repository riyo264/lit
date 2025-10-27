class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prevrow = 0, ans = 0;
        int n = bank.size();

        for (int i = 0; i < n; i++) {
            int currow = 0;
            for (char c : bank[i]) {
                if (c == '1') currow++;
            }
            if (currow > 0) {
                ans += prevrow * currow;
                prevrow = currow;
            }
        }
        return ans;
    }
};