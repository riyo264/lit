class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int longest = 1;
        unordered_set<int> set;
        for(int i = 0; i < n; i++)
        {
            set.insert(nums[i]);
        }

        for(auto it : set)
        {
            if(set.find(it - 1) == set.end()) {
                int cnt = 1;
                int x = it;
                while(set.find(x+1) != set.end()) {
                    x++;
                    cnt++;
                }
                longest = max(longest, cnt);
            }
        }
        
        return longest;
    }
};