class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> Q;
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(Q.empty()==0 && (Q.front() <= i-k))
            {
                Q.pop_front();
            }
            while(Q.empty()==0 && (nums[i] >= nums[Q.back()]))
            {
                Q.pop_back();
            }
            Q.push_back(i);
            if(i >= k-1)
            {
                ans.push_back(nums[Q.front()]);
            }
        }
        return ans;
    }
};