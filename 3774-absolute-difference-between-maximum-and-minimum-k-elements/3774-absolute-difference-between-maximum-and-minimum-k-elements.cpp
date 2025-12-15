class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int smallest = 0;
        int largest = 0;
        int n = nums.size();
        for(int i = 0; i < k; i++)
        {
            smallest += nums[i];
        }
        for(int i = n-1; i > n-1-k; i--) {
            largest += nums[i];
        }
        return abs(largest - smallest);
    }
};