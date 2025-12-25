class Solution {
public:
    int largestHistogram(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int area = 0;
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && (nums[st.top()] >= nums[i])) 
            {
                int height = nums[st.top()];
                st.pop();
                if(st.empty()) {
                    area = max(area, height*(i+1-1));
                }
                else {
                    area = max(area, height*(i-st.top()-1));
                }
            }
            st.push(i);
        }
        while(!st.empty()) {
            int height = nums[st.top()];
            st.pop();
            if(st.empty()) {
                area = max(area, height*(n+1-1));
            }
            else {
                area = max(area, height*(n-st.top()-1));
            }
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;
        vector<vector<int>> p_sum(n, vector<int>(m, 0));
        for(int j = 0; j < m; j++)
        {
            int sum = 0;
            for(int i = 0; i < n; i++)
            {
                if(matrix[i][j]-'0' == 1) {
                    sum += 1;
                }
                else {
                    sum = 0;
                }
                p_sum[i][j] = sum;
            }
        }
        for(int i = 0; i < n; i++)
        {
            maxArea = max(maxArea, largestHistogram(p_sum[i]));
        }
        return maxArea;
    }
};