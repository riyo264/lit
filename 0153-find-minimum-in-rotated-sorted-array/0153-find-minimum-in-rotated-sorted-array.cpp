class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = -1;

        while(low <= high)
        {
            int mid = (low + high)/2;

            if(nums[mid]>=nums[low] && nums[mid]<=nums[high])
            {
                if(ans == -1 || ans > nums[low])
                {
                    ans = nums[low];
                    return ans;
                }
                else
                {
                    high = mid - 1;
                }
            }
            else if(nums[mid]>=nums[low] && nums[mid]>nums[high])
            {
                if(ans == -1 || ans > nums[low]){
                ans = nums[low];
                low = mid + 1;
                }
                else{
                low = mid + 1;
                }
            }
            else if(nums[mid]<nums[high] && nums[mid]<=nums[low])
            {
                if(ans == -1 || ans > nums[mid])
                {
                    ans = nums[mid];
                    high = mid - 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            
        }
        return ans;
    }
};