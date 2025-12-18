class Solution {
public:
    bool completePrime(int num) {
       string s = to_string(num);
       int n = s.size();
       string temp = "";
       for(int i = 0; i < n; i++)
       {
            temp.push_back(s[i]);
            int x = stoi(temp);
            if(x == 1) {
                return false;
            }
            if(x == 2) {
                continue;
            }
            for(int i = 2; i < x; i++)
            {
                if(x % i == 0) {
                    return false;
                }
            }
       }
       string temp1 = "";
       for(int i = n-1; i >= 0; i--)
       {
            temp1.push_back(s[i]);
            string r = temp1;
            reverse(r.begin(), r.end());
            int x = stoi(r);
            if(x == 1) {
                return false;
            }
            if(x == 2) {
                continue;
            }
            for(int i = 2; i < x; i++)
            {
                if(x % i == 0) {
                    return false;
                }
            }
       }
       return true;
    }
};