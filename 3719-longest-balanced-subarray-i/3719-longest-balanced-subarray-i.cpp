class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int len = INT_MIN;
        vector<int> vis(100001, 0);
        int t = 1;
        for(int i = 0; i < n; i++)
        {
            int j = i;
            int odd = 0;
            int even = 0;
            int l = 0;
            t++;
            while(j < n) {
                if(nums[j] % 2 == 0 && vis[nums[j]] != t) {
                    even++;
                    vis[nums[j]] = t;
                }
                else if(nums[j] % 2 != 0 && vis[nums[j]] != t) {
                    odd++;
                    vis[nums[j]] = t;
                }
                l++;
                if(odd == even && odd != 0) {
                    len = max(l, len);
                }
                j++;
            }
        }
        if(len == INT_MIN) {
            return 0;
        }
        return len;
    }
};