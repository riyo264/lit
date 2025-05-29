class Solution {
public:
    long long binSubarray(vector<int>& nums, int goal)
    {
        if(goal < 0)
        {
            return 0;
        }
        int l = 0;
        int r = 0;
        long long sum = 0;
        long long cnt = 0;
        while(r < nums.size())
        {
            sum = sum + (nums[r]);
            while(sum > goal)
            {
                sum = sum - (nums[l]);
                l++;
            }
            cnt = cnt + (r-l+1);
            r++;
        }
        return cnt;
    }
    long long numSubarraysWithSum(vector<int>& nums, int goal) {
        long long a = binSubarray(nums, goal);
        long long b = binSubarray(nums, goal-1);
        return a-b;
    }
};