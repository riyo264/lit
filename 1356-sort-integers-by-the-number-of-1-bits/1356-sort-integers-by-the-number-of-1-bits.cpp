class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int bina = __builtin_popcount(a);
            int binb = __builtin_popcount(b);
            return bina != binb ? bina < binb : a < b;
        });

        return arr;
    }
};