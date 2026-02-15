class Solution {
public:
    string addBinary(string a, string b) {
        int n = max(a.size(), b.size());
        string ans;
        while(a.size() != b.size()) 
        {
            if(a.size() < b.size()) {
                a = '0' + a;
            }
            else {
                b = '0' + b;
            }
        }
        bool carry = false;
        for(int i = n-1; i > -1; i--)
        {
            if(a[i] == '1' && b[i] == '1') {
                if(!carry) {
                    ans.push_back('0');
                    carry = true;
                }
                else {
                    ans.push_back('1');
                    carry = true;
                }
            }
            else if(a[i] == '1' || b[i] == '1') {
                if(!carry) {
                    ans.push_back('1');
                    carry = false;
                }
                else {
                    ans.push_back('0');
                    carry = true;
                }
            }
            else {
                if(!carry) {
                    ans.push_back('0');
                    carry = false;
                }
                else {
                    ans.push_back('1');
                    carry = false;
                }
            }
        }
        if(carry) {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};