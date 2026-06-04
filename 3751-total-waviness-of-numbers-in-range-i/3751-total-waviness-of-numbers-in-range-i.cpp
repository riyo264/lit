class Solution {
public:
    int totalWaviness(int num1, int num2) {
        if(num2 <= 100) {
            return 0;
        } 
        int wav = 0;
        for(int i = num1; i <= num2; i++)
        {
            string s = to_string(i);
            int n = s.size();
            for(int j = 1; j < n-1; j++)
            {
                if(s[j] > s[j-1] && s[j] > s[j+1]) {
                    wav++;
                }
                else if(s[j] < s[j-1] && s[j] < s[j+1]) {
                    wav++;
                }
            }
        }
        return wav;
    }
};