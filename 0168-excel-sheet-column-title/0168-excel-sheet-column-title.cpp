class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s;
        int n = columnNumber;
        while(n > 0) 
        {
            n--;
            int rem = n % 26;
            s.push_back('A' + rem);
            n /= 26;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};