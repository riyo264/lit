class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        while(true)
        {
            int temp = x%10;
            ans = (ans*10) + temp;
            if (ans > INT_MAX || ans < INT_MIN) {
                return 0; // overflow
            }
            if(x%10 == x) {
                break;
            }
            x /= 10;
        }
        return (int)ans;
    }
};