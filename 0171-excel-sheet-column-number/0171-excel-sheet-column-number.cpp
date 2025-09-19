class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        int column = 0;
        for(char c : columnTitle)
        {
            column = column * 26 + (c - 'A' + 1);
        }
        return column;
    }
};