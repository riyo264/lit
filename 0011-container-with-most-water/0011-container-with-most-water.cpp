class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int maxvol = 0;
        while(l < r)
        {
            int y = min(height[l], height[r]);
            maxvol = max(maxvol, y*(r-l));
            if(height[l] < height[r]) {
                l++;
            }
            else if(height[l] > height[r]) {
                r--;
            }
            else {
                r--;
            }
        }
        return maxvol;
    }
};