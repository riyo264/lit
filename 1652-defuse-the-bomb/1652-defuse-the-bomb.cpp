class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans(code.size());
        int n = code.size();
        for(int i = 0; i < code.size(); i++)
        {
            if(k > 0) {
                ans[i] = 0;
                for(int j = 1; j <= k; j++)
                {
                    int l = (i+j)%n;
                    ans[i] = ans[i] + code[l];
                }
            }
            else if(k < 0) {
                ans[i] = 0;
                for(int j = 1; j <= abs(k); j++) 
                {
                    int l = 0;
                    if(i-j >= 0) {
                        l = (i-j);
                        ans[i] += code[l];
                    }
                    else {
                        l = n+(i-j);
                        ans[i] += code[l];
                    }
                }
            }
            else {
                ans[i] = 0;
            }
        }
        return ans;
    }
};