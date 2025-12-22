class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> first, last;
        sort(nums.begin(), nums.end());
        if(n % 2 == 0) {
            for(int i = 0; i < n/2; i++)
            {
                first.push_back(nums[i]);
            }
            for(int i = n/2; i < n; i++)
            {
                last.push_back(nums[i]);
            }
        }
        else {
            for(int i = 0; i < n/2+1; i++)
            {
                first.push_back(nums[i]);
            }
            for(int i = n/2+1; i < n; i++)
            {
                last.push_back(nums[i]);
            }
        }
        int k = 0;
        int i = first.size()-1;
        int j = last.size()-1;
        while(k < n) 
        {
            if(k % 2 == 0) {
                nums[k] = first[i];
                i--;
            }
            else {
                nums[k] = last[j];
                j--;
            }
            k++;
        }
    }
};