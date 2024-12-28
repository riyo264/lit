class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool x = false;
        
        for(int i = 0; i < matrix.size(); i++){
            int low = 0;
            int high = matrix[i].size()-1;

            while(low <= high)
            {
                int mid = (low + high)/2;
                if(matrix[i][mid]==target)
                {
                    x = true;
                    return x;
                }
                else if(matrix[i][mid]<target)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return x;
    }
};