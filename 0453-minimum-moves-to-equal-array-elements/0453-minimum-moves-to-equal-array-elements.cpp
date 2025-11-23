class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ref = nums[0];
        int op = 0;
        for(int i = 1; i < n; i++)
        {
            op += nums[i] - ref;
        }
        return op;
    }
};