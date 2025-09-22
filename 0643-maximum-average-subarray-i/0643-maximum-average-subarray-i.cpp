class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxavgsum = -DBL_MAX;
        int windowSum = 0;
        int n = nums.size();
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }
        maxavgsum = static_cast<double>(windowSum) / k;
        for (int i = k; i < n; i++) {
            windowSum += nums[i] - nums[i - k];
            double avg = static_cast<double>(windowSum) / k;
            if (avg > maxavgsum) {
                maxavgsum = avg;
            }
        }

        return maxavgsum;
    }
};