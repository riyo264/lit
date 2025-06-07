class Solution {
public:
    string largestOddNumber(string num) {
        string result;
        int n = num.size();
        int index = -1;
        for(int i = n-1; i > -1; i--)
        {
            if(num[i]=='1' || num[i]=='3' || num[i]=='5' || num[i]=='7' || num[i]=='9')
            {
                index = i;
                break;
            }
        }
        if(index > -1)
        {
            for(int i = 0; i < index+1; i++)
            {
                result.push_back(num[i]);
            }
        }
        else {
            result = "";
        }
        return result;
    }
};