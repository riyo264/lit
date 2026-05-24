class Solution {
public:
    int solve(int i, vector<int>& arr, int d, vector<int>& dp) {
        int n = arr.size();
        if(i > 0 && i < n-1 && arr[i+1] >= arr[i] && arr[i-1] >= arr[i]) {
            return 1;
        }
        if(i == 0 && arr[i+1] > arr[i]) {
            return 1;
        }
        if(i == n-1 && arr[i-1] > arr[i]) {
            return 1;
        }
        if(dp[i]!=-1)return dp[i];
        int jumps = 0;
        if(i > 0) {
            for(int j = i-1; j >= max(0, i-d); j--)
            {
                if(arr[j] >= arr[i]) {
                    break;
                }
                else {
                    jumps = max(jumps, 1 + solve(j, arr, d, dp));
                }
            }
        }
        if(i < n-1) {
            for(int j = i+1; j <= min(n-1, i+d); j++)
            {
                if(arr[j] >= arr[i]) {
                    break;
                }
                else {
                    jumps = max(jumps, 1 + solve(j, arr, d, dp));
                }
            }
        }
        return dp[i] = jumps;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        int ans = 0;
        vector<int> dp(n+1, -1);
        if(n == 1) {
            return 1;
        }
        for(int i = 0; i < n; i++)
        {
            ans = max(ans, solve(i, arr, d, dp));
        }
        return ans;
    }
};