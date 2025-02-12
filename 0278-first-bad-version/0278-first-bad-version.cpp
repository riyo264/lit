// The API isBadVersion is defined for you.
// bool isBadVersion(long long version);

class Solution {
public:
    long long firstBadVersion(long long n) {
        long long ans = -1;
        long long low = 1;
        long long high = n;
        while(low<=high)
        {
            long long mid = (low+high)/2;
            if(isBadVersion(mid)==true)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};