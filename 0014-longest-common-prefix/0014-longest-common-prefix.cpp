class Solution {
public:
    int length(vector<string>& strs) {
        int len = strs[0].size();
        int n = strs.size();
        for(int i = 1; i < n; i++){
            if(len > strs[i].size())
            {
                len = strs[i].size();
            }
            else
            {
                continue;
            }
        }
        return len;
    }
    string longestCommonPrefix(vector<string>& strs) {
        char temp;
        int n = length(strs);
        int m = strs.size();
        int sign = 0;
        string pref;
        for(int i = 0; i < n; i++)
        {
            temp = (strs[0][i]);
            for(int j = 0; j < m; j++)
            {
                if(strs[j][i] == temp)
                {
                    if(j == m-1)
                    {
                        pref.push_back(temp);
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    sign = 1;
                    break;
                }
            }
            if(sign == 1)
            {
                break;
            }
        }
        return pref;
    }
};