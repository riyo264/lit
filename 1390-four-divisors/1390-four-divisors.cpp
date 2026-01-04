class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            vector<int> div;
            int floor = sqrt(nums[i]);
            for(int j = 1; j <= floor; j++)
            {
                if(nums[i] % j == 0) {
                    div.push_back(j);
                    if(nums[i]/j != j) {
                        div.push_back(nums[i]/j);
                    }
                }
            }
            if(div.size() == 4) {
                for(int k = 0; k < 4; k++)
                {
                    ans += div[k];
                }
            }
        }
        return ans;
    }
};