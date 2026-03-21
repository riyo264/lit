class Solution {
public:
    int minCost(int n) {
        int cost = 0;
        int j = 0;
        while(j < n) {
            cost += j;
            j++;
        }
        return cost;
    }
};