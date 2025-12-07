class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        int i = n-1;
        int j = m-1;
        string ans = "";
        int carry = 0;
        while(i >= 0 || j >= 0 || carry > 0)
        {
            int s1 = 0;
            int s2 = 0;
            if(i >= 0) {
                s1 = num1[i] - '0';
            }
            if(j >= 0) {
                s2 = num2[j] - '0';
            }
            int x = s1 + s2 + carry;
            ans.push_back((x%10) + '0');
            carry = x/10;
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};