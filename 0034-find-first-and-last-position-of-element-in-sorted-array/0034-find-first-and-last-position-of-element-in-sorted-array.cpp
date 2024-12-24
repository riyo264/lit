class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        int first = -1;
        int last = -1;

        // First occur
        int low = 0;
        int high = n-1;
        while(low <= high)
        {
            int mid = (high+low)/2;

            if(nums[mid]==target)
            {
                first = mid;
                high = mid - 1;
            }
            else if(nums[mid]<target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        ans.push_back(first);

        // Last occur
        int low1 = 0;
        int high1 = n-1;
        while(low1 <= high1)
        {
            int mid1 = (high1 + low1)/2;
            
            if(nums[mid1]==target)
            {
                last = mid1;
                low1 = mid1 + 1;
            }
            else if(nums[mid1]<target)
            {
                low1 = mid1 + 1;
            }
            else
            {
                high1 = mid1 - 1;
            }
        }
        ans.push_back(last);

        return ans;
    }
};