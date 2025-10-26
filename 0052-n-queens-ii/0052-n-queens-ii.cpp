class Solution {
    void arrangements(vector<string>& queens, int n, int col, int& ans, vector<int>& leftcheck, vector<int>& upperdiagonal, vector<int>& lowerdiagonal) {
        if(col == n) {
            ans++;
            return;
        }

        for(int r = 0; r < n; r++) 
        {
            if(leftcheck[r] == 0 && upperdiagonal[r+col] == 0 && lowerdiagonal[(n-1) + col - r] == 0) {
                queens[r][col] = 'Q';
                leftcheck[r] = 1;
                upperdiagonal[r+col] = 1;
                lowerdiagonal[(n-1) + col - r] = 1;
                arrangements(queens, n, col+1, ans, leftcheck, upperdiagonal, lowerdiagonal);
                queens[r][col] = '.';
                leftcheck[r] = 0;
                upperdiagonal[r+col] = 0;
                lowerdiagonal[(n-1) + col - r] = 0;
            }
        }
    }
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<string> queens(n, string(n, '.'));
        vector<int> leftcheck(n, 0), upperdiagonal(2 * n - 1, 0), lowerdiagonal(2 * n - 1, 0);
        arrangements(queens, n, 0, ans, leftcheck, upperdiagonal, lowerdiagonal);
        return ans;
    }
};