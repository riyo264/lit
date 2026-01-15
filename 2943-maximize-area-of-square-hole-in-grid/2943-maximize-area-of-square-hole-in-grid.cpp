class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int h = hBars.size();
        int v = vBars.size();
        int cnt1 = 2;
        int cnt2 = 2;
        int temp1 = 2;
        int temp2 = 2;
        int h1 = 0;
        int v1 = 0;
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        while(h-1 > h1) 
        {
            if(hBars[h1] + 1 == hBars[h1+1]) {
                temp1++;
                cnt1 = max(cnt1, temp1);
            }
            else {
                temp1 = 2;
            }
            h1++;
        }
        while(v-1 > v1) 
        {
            if(vBars[v1] + 1 == vBars[v1+1]) {
                temp2++;
                cnt2 = max(cnt2, temp2);
            }
            else {
                temp2 = 2;
            }
            v1++;
        }
        int sq = min(cnt1, cnt2);
        return sq*sq;
    }
};