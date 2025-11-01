class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int pref = 0;
        int n = nums.size();
        int cnt = 0;
        int total_sum = 0;
        for(int i = 0; i < n; i++)
        {
            total_sum += nums[i];
        }
        int suf = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0) {
                suf = total_sum - pref;
                if(suf == pref) {
                    cnt += 2;
                }
                else if(abs(suf - pref) == 1) {
                    cnt++;
                }
            }
            pref += nums[i];
        }
        return cnt;
    }
};