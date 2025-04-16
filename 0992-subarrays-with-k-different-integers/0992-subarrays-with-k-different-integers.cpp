class Solution {
public:
    int subarray1(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int cnt = 0;
        unordered_map<int, int> mpp;
        while(r < nums.size())
        {
            mpp[nums[r]]++;
            while(mpp.size() > k)
            {
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0)
                {
                    mpp.erase(nums[l]);
                }
                l++;
            }
            cnt = cnt + (r-l+1);
            r++;
        }
        return cnt;
    }
    int subarray2(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int cnt = 0;
        unordered_map<int, int> mpp;
        while(r < nums.size())
        {
            mpp[nums[r]]++;
            while(mpp.size() > k-1)
            {
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0)
                {
                    mpp.erase(nums[l]);
                }
                l++;
            }
            cnt = cnt + (r-l+1);
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans1;
        int ans2;
        ans1 = subarray1(nums, k);
        ans2 = subarray2(nums, k);
        return (ans1 - ans2);
    }
};