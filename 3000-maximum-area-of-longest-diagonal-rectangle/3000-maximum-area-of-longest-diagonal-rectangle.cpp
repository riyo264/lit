class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double max_dia = INT_MIN;
        int max_area = INT_MIN;
        int len = -1;
        int bred = -1;
        for(auto it : dimensions) 
        {
            double temp = max_dia;
            int temp1 = max_area;
            int s1 = pow(it[0], 2);
            int s2 = pow(it[1], 2);
            double dia = pow((s1+s2), 0.5);
            int check = it[0] * it[1];
            if(dia > max_dia) {
                max_dia = dia;
                max_area = check;
            }
            else if(dia == max_dia && check > max_area) {
                max_area = check;
            }
        }
        return max_area;
    }
};