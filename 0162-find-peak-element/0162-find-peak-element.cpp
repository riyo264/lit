class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        if(n == 1)
        {
            ans = 0;
        }

        else if(n == 2)
        {
            if(nums[0]>nums[1])
            {
                ans = 0;
            }
            else
            {
                ans = 1;
            }
        }

        else
        {
        int low = 1;
        int high = n - 2;
        while(low <= high)
        {
            int mid = (low + high)/2;

        if(nums[0]>nums[1])
        {
            ans = 0;
            break;
        }
        else if(nums[n-1]>nums[n-2])
        {
            ans = n-1;
            break;
        }
        
           else if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
            {
                ans = mid;
                break;
            }
            else if(nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1])
            {
                low = mid + 1;
            }
            else if(nums[mid]<nums[mid-1] && nums[mid]>nums[mid+1]){
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        }
        return ans;
    }
};