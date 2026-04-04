class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int len = encodedText.size();
        int cols = (len/rows);
        string ans;
        vector<vector<char>> matrix(rows, vector<char>(cols, ' '));
        int k = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                matrix[i][j] = encodedText[k];
                k++;
            }
        }
        for(int i = 0; i < cols; i++) 
        {
            int r = 0, j = i;
            while(r < rows && j < cols) 
            {
                ans.push_back(matrix[r][j]);
                r++;
                j++;
            }
        }
        while(!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }
        return ans;
    }
};