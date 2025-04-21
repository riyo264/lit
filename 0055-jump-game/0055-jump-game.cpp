class Solution {
public:
    bool canJump(vector<int>& nums) {
        int Maxindex = 0;
        bool x = true;;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > Maxindex)
            {
                return false;
            }
            else
            {
                Maxindex = max(i + nums[i], Maxindex);
            }
            if(Maxindex >= nums.size()-1)
            {
                return true;
            }
        }
        return x;
    }
};