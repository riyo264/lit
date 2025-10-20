class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        string s;
        for(int i = 0; i < n; i++)
        {
            if(i == n-1) {
                s += to_string(nums[i]);
                ans.push_back(s);
                s = "";
            }
            else if(nums[i+1] != nums[i]+1) {
                s += to_string(nums[i]);
                ans.push_back(s);
                s = "";
            }
            else if(nums[i+1] != nums[i]+1 && s.empty()) {
                s += to_string(nums[i]);
                ans.push_back(s);
                s = "";
            }
            else if(s.empty()) {
                s += to_string(nums[i]);
                s = s + "->";
            }
        }
        return ans;
    }
};