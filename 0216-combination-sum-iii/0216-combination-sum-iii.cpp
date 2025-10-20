class Solution {
    void sequences(int i, int k, int n, long long& sum, vector<int>& arr, vector<vector<int>>& combinations) {
        if(sum == n && arr.size() == k) {
            combinations.push_back(arr);
            return;
        }
        if(sum > n || arr.size() > k || i > 9) return;
        arr.push_back(i);
        sum += i;
        sequences(i+1, k, n, sum, arr, combinations);
        sum -= arr[arr.size()-1];
        arr.pop_back();
        sequences(i+1, k, n, sum, arr, combinations);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> combinations;
        int i = 1;
        vector<int> arr;
        long long sum = 0;
        sequences(i, k, n, sum, arr, combinations);
        return combinations;
        }
};