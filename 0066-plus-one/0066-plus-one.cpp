class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        int n = v.size();
        if(v[n-1] != 9) {
            v[n-1]++;
            return v;
        }
        int i = n-1;
        while(v[i] == 9) {
            if(i == 0) {
                v[i] = 1;
                v.push_back(0);
                break;
            }
            v[i] = 0;
            i--;
        }
        return v;
    }
};