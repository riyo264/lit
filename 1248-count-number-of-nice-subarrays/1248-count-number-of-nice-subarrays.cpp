class Solution {
public:

    // We are basically using this function to calculate the number of sub arrays whose number of odd numbers are less than equal to k
    int niceSubarrays(vector<int>& nums, int k)
    {
        if(k < 0)
        {
            return 0;
        }
        int l = 0;
        int r = 0;
        int sum = 0;
        int cnt = 0;
        while(r < nums.size())
        {
            sum = sum + (nums[r]%2);
            while(sum > k)
            {
                sum = sum - (nums[l]%2);
                l++;
            }
            cnt = cnt + (r-l+1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int a = niceSubarrays(nums, k);
        int b = niceSubarrays(nums, k-1);
        return a-b;
    }
};