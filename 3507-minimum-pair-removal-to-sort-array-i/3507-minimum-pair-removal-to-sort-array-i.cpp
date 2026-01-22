class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int cnt = 0;
        while(!is_sorted(nums.begin(), nums.end())) 
        {
            cnt++;
            int mini = INT_MAX;
            int ind = 0;
            int temp = mini;
            for(int i = 0; i < nums.size() - 1; i++) 
            {
                mini = min(nums[i] + nums[i+1], mini);
                if(mini < temp) {
                    ind = i;
                    temp = mini;
                }
            }
            nums[ind+1] = mini;
            nums.erase(nums.begin()+ind);
        }
        return cnt;
    }
};