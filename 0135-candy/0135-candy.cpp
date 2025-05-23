class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum = 1;
        int i = 1;
        while(i < n) 
        {
            if(ratings[i]==ratings[i-1]){
            sum++;
            i++;
            continue;
            }
            int peak = 1;
            while(i < n && ratings[i] > ratings[i-1])
            {
                peak++;
                sum = sum + peak;
                i++;
            }
            int dip = 1;
            while(i < n && ratings[i] < ratings[i-1])
            {
                sum = sum + dip;
                i++;
                dip++;
            }
            if(dip > peak)
            {
                sum = sum + (dip-peak);
            }
        }
        return sum;
    }
};