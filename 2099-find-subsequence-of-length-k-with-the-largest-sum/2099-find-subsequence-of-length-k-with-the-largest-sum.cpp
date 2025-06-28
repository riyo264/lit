class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> result;
        vector<int> temp = nums; 
        if(k == nums.size())
        {
            return nums;
        }
       vector<pair<int, int>> withIndex;
for (int i = 0; i < nums.size(); i++) {
    withIndex.push_back({nums[i], i});
}

sort(withIndex.begin(), withIndex.end(), [](auto &a, auto &b) {
    return a.first > b.first;
});

vector<int> ansi;
for (int i = 0; i < k; i++) {
    ansi.push_back(withIndex[i].second);
}

sort(ansi.begin(), ansi.end());

for (int i : ansi) {
    result.push_back(nums[i]);
}
return result;
    }
};