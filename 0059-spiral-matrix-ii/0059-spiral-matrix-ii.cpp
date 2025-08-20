class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int check = pow(n, 2);
        vector<vector<int>> ans(n, vector<int>(n, -1));
        int p = 1;
        int top = 0, bottom = n-1, left = 0, right = n-1;

        while(top <= bottom && left <= right) {
            if(p > check) {
                break;
            }
            for(int i = left; i <= right; i++)
            {
                ans[top][i] = p;
                p++;
            }
            top++;
            if(p > check) {
                break;
            }
            for(int i = top; i <= bottom; i++)
            {
                ans[i][right] = p;
                p++;
            }
            right--;
            if(p > check) {
                break;
            }
            if(top <= bottom) {
                for(int i = right; i >= left; i--)
                {
                    ans[bottom][i] = p;
                    p++;
                }
                bottom--;
                if(p > check) {
                    break;
                }
            }
            if(left <= right) {
                for(int i = bottom; i >= top; i--)
                {
                    ans[i][left] = p;
                    p++;
                }
                left++;
                if(p > check) {
                    break;
                }
            }
        }
        return ans;
    }
};