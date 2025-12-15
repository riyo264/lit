class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        int i = 0;
        int j = 0;
        long long dec = 0;
        while(i < n && j < n) {
            dec++;
            if(j != n-1 && prices[j] == prices[j+1] + 1) {
                j++;
            }
            else {
                if(i != j) {
                    long long x = j - i + 1;
                    dec += ((x*(x+1))/2 - x);
                    i = j + 1;
                    j++;
                }
                else {
                    i = j + 1;
                    j++;
                }
            }
        }
        return dec;
    }
};