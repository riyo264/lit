class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> index;
        for(int i = 0; i < nums.size(); i++) 
        {
            if(nums[i]==key) {
                int it = max(0, i-k);
                if(index.size() > 0 && it<=index[index.size()-1]) {
                    it = index[index.size()-1]+1;
                }
                for(int j = it; j <= i+k; j++)
                {
                    if(j < nums.size()) {
                        index.push_back(j);
                    }
                }
            }
            else {
                continue;
            }
        }
        return index;
    }
};