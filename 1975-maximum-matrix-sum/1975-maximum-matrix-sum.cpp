class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int neg_cnt = 0;
        long long sum = 0;
        int mini = INT_MAX;
        bool zero = false;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                sum += abs(matrix[i][j]);
                mini = min(mini, abs(matrix[i][j]));
                if(matrix[i][j] < 0) {
                    neg_cnt++;
                }
                else if(matrix[i][j] == 0) {
                    zero = true;
                }
            }
        }
        if(neg_cnt % 2 == 0 || zero == true) {
            return sum;
        }
        else {
            return (sum - (2*mini));
        }
        return 0;
    }
};