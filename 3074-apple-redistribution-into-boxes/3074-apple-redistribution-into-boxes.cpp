class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();
        sort(capacity.rbegin(), capacity.rend());
        vector<int> pref_cap(m);
        int pref_sum = 0;
        for(int i = 0; i < m; i++)
        {
            pref_sum += capacity[i];
            pref_cap[i] = pref_sum; 
        }
        int total_apples = 0;
        for(int i = 0; i < n; i++)
        {
            total_apples += apple[i];
        }
        int ans = 0;
        for(int i = 0; i < m; i++)
        {
            if(pref_cap[i] >= total_apples) {
                ans = (i+1);
                break;
            }
        }
        return ans;
    }
};