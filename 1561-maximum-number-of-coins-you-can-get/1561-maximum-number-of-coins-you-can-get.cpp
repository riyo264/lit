class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        int i = 0, j = n-2;
        sort(piles.begin(), piles.end());
        int coins = 0;
        while(i < j) {
            coins += piles[j];
            j -= 2;
            i++;
        }
        return coins;
    }
};