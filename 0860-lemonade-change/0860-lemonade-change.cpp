class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int sum = 0;
        unordered_map<int, int> mpp = {{5, 0}, {10, 0}, {20, 0}};
        for(int i = 0; i < bills.size(); i++)
        {
            if(bills[i]==5)
            {
                mpp[5]++;
                sum = sum + 5;
            }
            else if(bills[i]==10)
            {
                if(mpp[5]==0)
                {
                    return false;
                }
                else{
                    mpp[10]++;
                    mpp[5]--;
                }
            }
            else if(bills[i]==20)
            {
                if((mpp[10]>=1 && mpp[5]>=1))
                {
                    mpp[20]++;
                    mpp[10]--;
                    mpp[5]--;
                }
                else if(mpp[5] >= 3)
                {
                    mpp[20]++;
                    mpp[5] = mpp[5] - 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};