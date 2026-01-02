class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int i : nums) 
        {
            if(mpp.count(i)) {
                return i;
            } 
            mpp[i]++;
        }
        return 0;
    }
};