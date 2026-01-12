class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int i = 0;
        int time = 0;
        while(i < n-1) 
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            int x2 = points[i+1][0];
            int y2 = points[i+1][1];
            while(x1 != x2 || y1 != y2) {
                if(x1 < x2) {
                    x1++;
                }
                else if(x2 < x1) {
                    x2++;
                }
                if(y1 < y2) {
                    y1++;
                }
                else if(y2 < y1) {
                    y2++;
                }
                time++;
            }
            i++;
        }
        return time;
    }
};