class Solution {
public:
    string largestGoodInteger(string num) {
        string ans;
        int l = 0;
        int r = 2;
        int x = 0;
        int n = INT_MIN;
        while(r < num.size())
        {
            bool flag = false;
            string s;
            for(int i = l; i <= r; i++)
            {
                char c = num[l];
                if(num[i] != c) {
                    break;
                }
                else {
                    s.push_back(num[i]);
                }
                if(s.size() == 3) {
                    flag = true;
                }
            }
            if(flag) {
                x = stoi(s);
                n = max(x, n);
            }
            l++;
            r++;
        }
        if(n != INT_MIN) {
            ans = to_string(n);
        }
        string res;
        if(ans == "0")
        {
            res.push_back('0');
            res.push_back('0');
            res.push_back('0');
        }
        else {
            res = ans;
        }
        return res;
    }
};