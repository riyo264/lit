class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int h = n-2;
        int l = 1;
        if(n == 1)
        {
            return nums[0];
        }
        else if(nums[0]!=nums[1])
        {
            return nums[0];
        }
        else if(nums[n-1]!=nums[n-2])
        {
            return nums[n-1];
        }
        while(l <= h)
        {
            int mid = (l+h)/2;
            if(nums[mid-1]!=nums[mid] && nums[mid+1]!=nums[mid])
            {
                return nums[mid];
            }
            else if(mid%2 == 0)
            {
                if(nums[mid]==nums[mid+1])
                {
                    l = mid + 1;
                }
                else if(nums[mid] == nums[mid-1])
                {
                    h = mid - 1;
                }
            }
            else if(mid%2 != 0)
            {
                if(nums[mid]==nums[mid+1])
                {
                    h = mid - 1;
                }
                else if(nums[mid] == nums[mid-1])
                {
                    l = mid + 1;
                }
            }
        }
        return -1;
    }
};