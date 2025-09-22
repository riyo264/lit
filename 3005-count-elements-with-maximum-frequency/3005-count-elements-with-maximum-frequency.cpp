class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int cnt = 0;
        unordered_map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i]]++;
        }
        int freq = 0;
        for(auto x : mpp)
        {
            if(x.second == freq) {
                cnt += freq;
            }
            else if(x.second > freq) {
                freq = x.second;
                cnt = freq;
            }
        }
        return cnt;
    }
};