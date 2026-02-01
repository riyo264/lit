class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        int last = 0;
        int ans = duration;
        for(int i = 0; i < n-1; i++)
        {
            if(timeSeries[i] + duration - 1 >= timeSeries[i+1]) {
                ans += (timeSeries[i+1] - timeSeries[i]);
            }
            else {
                ans += duration;
            }
        }
        return ans;
    }
};