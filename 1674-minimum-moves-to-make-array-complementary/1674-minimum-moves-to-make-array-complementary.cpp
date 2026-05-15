class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> vec((limit << 1) + 2, 0);
        for (int i = 0; i < n >> 1; i++) {
            int mini = nums[i];
            int maxi = nums[n - 1 - i];
            if (mini > maxi) swap(mini, maxi);
            vec[2] += 2;
            vec[mini + 1]--;
            vec[mini + maxi]--;
            vec[mini + maxi + 1]++;
            vec[maxi + limit + 1]++;
        }
        int res = n, moves = 0;
        for (int targ = 2; targ <= limit * 2; targ++) {
            moves += vec[targ];
            res = min(res, moves);
        }
        return res;
    }
};