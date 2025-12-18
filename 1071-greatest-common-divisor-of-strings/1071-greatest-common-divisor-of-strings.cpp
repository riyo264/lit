class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string s = "";
        string s1 = str1 + str2;
        string s2 = str2 + str1;
        if(s1 != s2) {
            return s;
        }
        int n = str1.size();
        int m = str2.size();
        int g = gcd(n, m);
        for(int i = 0; i < g; i++)
        {
            s.push_back(str1[i]);
        }
        return s;
    }
};