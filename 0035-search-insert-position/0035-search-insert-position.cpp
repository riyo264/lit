class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = 0;

        while(low <= high)
        {
            int mid =(high+low)/2;

            if(nums[n-1]<target)
            {
                ans = n;
                break;
            }
            else if(nums[mid]>=target)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};