class Solution {
public:
    string clearDigits(string s) {
        int n = s.length();
        for(int i = 0; i<n; i++)
        {
            if((s[i]=='0') |(s[i]=='1') |(s[i]=='2') |(s[i]=='3') |(s[i]=='4') |(s[i]=='5') |(s[i]=='6') |(s[i]=='7') |(s[i]=='8') |(s[i]=='9'))
            {
                if(i==0){
                    s.erase(s.begin()+i);
                    i = 0;
                }
                else{
                    //if((s[i-1]=='0') |(s[i-1]=='1') |(s[i-1]=='2') |(s[i-1]=='3') |(s[i-1]=='4') |(s[i-1]=='5') |(s[i-1]=='6') |(s[i-1]=='7') |(s[i-1]=='8') |(s[i-1]=='9'))
                    s.erase(s.begin()+i);
                    s.erase(s.begin()+(i-1));
                    i = 0;
                }
            }
            else if((s[i]!='0') |(s[i]!='1') |(s[i]!='2') |(s[i]!='3') |(s[i]!='4') |(s[i]!='5') |(s[i]!='6') |(s[i]!='7') |(s[i]!='8') |(s[i]!='9'))
            {
                continue;
            }
            else if((i == n-1) && (s[i]!='0') |(s[i]!='1') |(s[i]!='2') |(s[i]!='3') |(s[i]!='4') |(s[i]!='5') |(s[i]!='6') |(s[i]!='7') |(s[i]!='8') |(s[i]!='9'))
            {
                break;
            }
        }
        return s;
    }
};