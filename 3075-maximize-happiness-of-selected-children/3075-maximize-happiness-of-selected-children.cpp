class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        int n = happiness.size();
        sort(happiness.rbegin(), happiness.rend());
        int d = 0;
        for(int i = 0; i < n; i++)
        {
            if(d == k) {
                break;
            }
            else {
                if(happiness[i] >= d) {
                    ans += (long long)(happiness[i] - d);
                }
                d++;
            }
        }
        return ans;
    }
};