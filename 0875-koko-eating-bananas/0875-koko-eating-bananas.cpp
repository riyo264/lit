class Solution {
public:
    long long total_time(vector<int>& piles, int i)
    {
        long long req_time = 0;
        for(int j = 0; j < piles.size(); j++)
        {
            req_time = req_time + (piles[j]+i-1)/i;
        }
        return req_time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        stable_sort(piles.begin(), piles.end());
        int n = piles.size();
        int hi = piles[n-1];
        int lo = 1;
        int ans = INT_MAX;
        while(lo <= hi)
        {
            int mid = (lo+hi)/2;
            long long req_time = total_time(piles, mid);
            if(req_time <= h)
            {
                ans = mid;
                hi = mid - 1;
            }
            else if(req_time > h)
            {
                lo = mid + 1;
            }
        }
        return ans;
    }
};