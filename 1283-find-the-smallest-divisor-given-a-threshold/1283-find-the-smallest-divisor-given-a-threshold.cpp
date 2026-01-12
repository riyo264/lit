class Solution {
public:
    bool check(vector<int>& nums, int thres, int div) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++) 
        {
            sum += ceil((double)nums[i]/div);
        }
        if(sum <= thres) {
            return true;
        }
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 1;
        int h = nums[n-1];
        int ans = INT_MAX;
        while(l <= h) {
            int mid = (l+h) / 2;
            if(check(nums, threshold, mid)) {
                ans = min(ans, mid);
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};