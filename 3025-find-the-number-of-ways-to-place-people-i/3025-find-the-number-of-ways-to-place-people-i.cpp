class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int cnt = 0;
        for(int i = 0; i < points.size(); i++) 
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j = i+1; j < points.size(); j++) 
            {
                int x2 = points[j][0];
                int y2 = points[j][1];
                if(x2 > x1 && y2 < y1) {
                    bool flag = true;
                    for(int k = 0; k < points.size(); k++) 
                    {
                        if(k == i || k == j) continue;
                        int x3 = points[k][0];
                        int y3 = points[k][1];
                        if(x3 >= x1 && x3 <= x2 && y3 <= y1 && y3 >= y2) {
                            flag = false;
                            break;
                        }
                    }
                    if(flag) cnt++;
                }
                else if(x1 == x2) {
                    bool flag = true;
                    int maxi = max(y1, y2);
                    int mini = min(y1, y2);
                    for(int k = 0; k < points.size(); k++) 
                    {
                        if(k == i || k == j) continue;
                        int x3 = points[k][0];
                        int y3 = points[k][1];
                        if(x3 == x2 && y3 >= mini && y3 <= maxi) {
                            flag = false;
                            break;
                        } 
                    }
                    if(flag) cnt++;
                    else {
                        continue;
                    }
                }
                else if(y1 == y2) {
                    bool flag = true;
                    int maxi = max(x1, x2);
                    int mini = min(x1, x2);
                    for(int k = 0; k < points.size(); k++) 
                    {
                        if(k == i || k == j) continue;
                        int x3 = points[k][0];
                        int y3 = points[k][1];
                        if(y3 == y2 && x3 >= mini && x3 <= maxi) {
                            flag = false;
                            break;
                        } 
                    }
                    if(flag) cnt++;
                    else {
                        continue;
                    }
                }
            }
        }
        return cnt;
    }
};