class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int l = 0;
        int r = k-1;
        int n = nums.size();
        vector<int> ans;
        while(r < n) 
        {
            int sum = 0;
            unordered_map<int, int> mpp;
            for(int i = l; i <= r; i++) 
            {
                mpp[nums[i]]++;
            }
            vector<pair<int, int>> items(mpp.begin(), mpp.end());
            sort(items.begin(), items.end(), [](auto& a, auto& b) {
                if(a.second == b.second) return a.first > b.first;
                return a.second > b.second;
            });
            unordered_set<int> tx;
            for(int i = 0; i < items.size() && i < x; i++)
            {
                tx.insert(items[i].first);
            }
            for(int i = l; i <= r; i++) 
            {
                if(tx.count(nums[i])) sum += nums[i];
            }
            ans.push_back(sum);
            l++;
            r++;
        }
        return ans;
    }
};