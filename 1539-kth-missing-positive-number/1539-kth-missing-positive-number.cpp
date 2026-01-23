class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // last missing amount
        // search from number where the missing amount is less than k till the number when it reaches k or more
        // the (k - last missing amount) number is the answer.
        int l = 0;
        int h = arr.size()-1;
        int lma = 0;
        int first_num = 0;
        int last_num = 0;
        while(l <= h) {
            int m = h - (h-l)/2;
            if(arr[m] - (m+1) < k) {
                lma = arr[m] - (m+1);
                first_num = arr[m];
                l++;
            }
            else {
                last_num = arr[m];
                h--;
            }
        }
        int r = (k - lma);
        return first_num + r;
    }
};