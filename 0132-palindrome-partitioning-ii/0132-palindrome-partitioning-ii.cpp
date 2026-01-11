class Solution {
public:
    bool isPalindrome(int i, int j, string& s) {
        while(i < j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    // int Partitions(int i, string& s, vector<int>& dp) {
    //     int n = s.size();
    //     if(i == n) {
    //         return 0;
    //     }
    //     if(dp[i] != -1) return dp[i];
    //     int partitions = INT_MAX;
    //     for(int j = i; j < n; j++) {
    //         if(isPalindrome(i, j, s)) {
    //             int ways = 1 + Partitions(j+1, s, dp);
    //             partitions = min(partitions, ways);
    //         }
    //     }
    //     return dp[i] = partitions;
    // }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        // return Partitions(0, s, dp)-1;
        for(int i = n-1; i >= 0; i--) 
        {
            int partitions = INT_MAX;
            for(int j = i; j < n; j++) {
                if(isPalindrome(i, j, s)) {
                    int ways = 1 + dp[j+1];
                    partitions = min(partitions, ways);
                }
            }
            dp[i] = partitions;
        }
        return dp[0]-1;
    }
};