class Solution {
public:
    bool Time(vector<int>& dist, double hour, int speed) {
        double time = 0;
        for(int i = 0; i < dist.size(); i++)
        {
            time += ((double)dist[i]/(double)speed);
            if(i < dist.size()-1) {
                time = ceil(time);
            }
        }
        if(time <= hour) {
            return true;
        }
        return false;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        // Maximize the Minimum Speed
        double l = 1, h = 1e7;
        int ans = -1;
        while(l <= h) {
            int m = l + (h-l)/2;
            if(Time(dist, hour, m)) {
                ans = m;
                h = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ans;
    }
};