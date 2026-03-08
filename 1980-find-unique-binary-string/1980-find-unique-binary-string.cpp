class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        vector<int> arr;
        string ans;
        for(int i = 0; i < n; i++) 
        {
            unsigned long m = bitset<16>(nums[i]).to_ulong();
            arr.push_back((int)m);
        }

        for(int i = 0; i <= pow(2, 16); i++) {
            bool flag = true;
            for(int j = 0; j < n; j++) {
                if(i == arr[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                bitset<16> bin(i);
                ans = bin.to_string();
                break;
            }
        }
        string f;
        for(int i = 15-n+1; i < 16; i++) {
            f.push_back(ans[i]);
        }
        return f;
    }
};