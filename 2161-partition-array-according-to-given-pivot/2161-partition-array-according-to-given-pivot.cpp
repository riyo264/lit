class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans;
        vector<int> lar;
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] < pivot) {
                ans.push_back(nums[i]);
            }
            else if(nums[i] > pivot) {
                lar.push_back(nums[i]);
            }
            else {
                cnt++;
            }
        }
        while(cnt--) {
            ans.push_back(pivot);
        }
        for(int i = 0; i < lar.size(); i++)
        {
            ans.push_back(lar[i]);
        }
        return ans;
    }
};