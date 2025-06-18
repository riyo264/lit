class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mpp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int num = 0;
        for(int i = s.size()-1; i > -1; i--) 
        {
            if(i != s.size()-1 && mpp[s[i]] < mpp[s[i+1]]) {
                num = num - mpp[s[i]];
            }
            else {
                num = num + mpp[s[i]];
            }
        }
        return num;
    }
};