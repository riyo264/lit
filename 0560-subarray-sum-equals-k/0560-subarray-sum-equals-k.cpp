class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sub;
        int sum = 0;
        int cnt = 0;
        sub[0] = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];
            int check = sum - k;
            if(sub[check] != 0) {
                cnt = cnt + sub[check];
            }
            sub[sum]++;
        }
        return cnt;
    }
};