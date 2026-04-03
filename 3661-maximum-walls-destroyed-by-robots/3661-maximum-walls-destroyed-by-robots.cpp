class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        unordered_set<int> robot_set(robots.begin(), robots.end());
        int walls_at_robots = 0;
        vector<int> clean_walls;
        
        for (int w : walls) {
            if (robot_set.count(w)) {
                walls_at_robots++;
            } else {
                clean_walls.push_back(w);
            }
        }
        
        sort(clean_walls.begin(), clean_walls.end());
    
        int n = robots.size();
        vector<pair<int, int>> combined(n);
        for (int i = 0; i < n; ++i) {
            combined[i] = {robots[i], distance[i]};
        }
        sort(combined.begin(), combined.end());
        

        auto count_in_range = [&](long long left, long long right) -> int {
            if (left > right) return 0;
            auto start = lower_bound(clean_walls.begin(), clean_walls.end(), left);
            auto end = upper_bound(clean_walls.begin(), clean_walls.end(), right);
            return max(0, (int)(end - start));
        };
   
        int dp_L = count_in_range((long long)combined[0].first - combined[0].second, combined[0].first - 1);
        int dp_R = 0;
        
        for (int i = 1; i < n; ++i) {
            int X_prev = combined[i-1].first;
            int D_prev = combined[i-1].second;
            int X_curr = combined[i].first;
            int D_curr = combined[i].second;
            
            int r_bound = min(X_prev + D_prev, X_curr - 1);
            int l_bound = max(X_curr - D_curr, X_prev + 1);
            
            int r_cnt = count_in_range(X_prev + 1, r_bound);
            int l_cnt = count_in_range(l_bound, X_curr - 1);
            
            int u_i = 0;

            if ((long long)X_prev + D_prev >= (long long)X_curr - D_curr) {
                u_i = count_in_range(X_prev + 1, X_curr - 1);
            } else {
                u_i = r_cnt + l_cnt;
            }

            int new_dp_L = max(dp_L + l_cnt, dp_R + u_i);
            int new_dp_R = max(dp_L, dp_R + r_cnt);
            
            dp_L = new_dp_L;
            dp_R = new_dp_R;
        }
        
        int r_cnt_last = count_in_range(combined.back().first + 1, 
                                       (long long)combined.back().first + combined.back().second);
        
        return max(dp_L, dp_R + r_cnt_last) + walls_at_robots;
    }
};