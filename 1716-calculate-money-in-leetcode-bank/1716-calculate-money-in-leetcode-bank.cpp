class Solution {
public:
    int totalMoney(int n) {
        int Mon = 1;
        int total = 0;
        int temp = 0;
        for(int i = 0; i < n; i++) 
        {
            if(i % 7 == 0) {
                Mon = 1 + i/7;
                total += Mon;
                temp = Mon;
            }
            else {
                total += temp;
            }
            temp++;
        }
        return total;
    }
};