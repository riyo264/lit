class Solution {
public:
    int minOperations(string s) {
        int i = 1;
        int j = 1;
        int op = 0;
        int step = 0;
        string temp = s;
        if(temp[0] == '1') {
            step++;
            temp[0] = '0';
        }
        else {
            step++;
            temp[0] = '1';
        }
        while(j < temp.size()) 
        {
            if(temp[j-1] == '0') {
                if(temp[j] == '0') {
                    step++;
                    temp[j] = '1';
                }
            }
            else {
                if(temp[j] == '1') {
                    step++;
                    temp[j] = '0';
                } 
            }
            j++;
        }
        while(i < s.size()) 
        {
            if(s[i-1] == '0') {
                if(s[i] == '0') {
                    op++;
                    s[i] = '1';
                }
            }
            else {
                if(s[i] == '1') {
                    op++;
                    s[i] = '0';
                } 
            }
            i++;
        }
        return min(op, step);
    }
};