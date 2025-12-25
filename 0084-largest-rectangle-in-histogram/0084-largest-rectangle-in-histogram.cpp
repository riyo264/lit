class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxi = 0;
        st.push(0);
        for(int i = 1; i < n; i++)
        {
            while(!st.empty() && heights[i] < heights[st.top()]) {
                int j = st.top();
                st.pop();
                if(st.empty()) {
                    maxi = max(maxi, (heights[j]*(i)));
                }
                else {
                    maxi = max(maxi, (heights[j]*(i-st.top()-1)));
                }
            }
            st.push(i);
        }
        while(!st.empty()) 
        {
            int j = st.top();
            st.pop();
            if(st.empty()) {
                maxi = max(maxi, (heights[j]*(n+1-1)));
            }
            else {
                maxi = max(maxi, (heights[j]*(n-st.top()-1)));
            }
        }
        return maxi;
    }
};