class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }
        int idx = 0; 
        int del = 1;
        vector<vector<char>> smat(numRows);
        for(int i = 0; i < s.size(); i++)
        {
            smat[idx].push_back(s[i]);
            if(idx == 0) {
                del = 1;
            }
            else if(idx == numRows - 1) {
                del = -1;
            }
            idx += del;
        }
        string result;
        for(int i = 0; i < numRows; i++)
        {
            for(int j = 0; j < smat[i].size(); j++)
            {
                result.push_back(smat[i][j]);
            }
        }
        return result;
    }
};