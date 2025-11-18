class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n =  bits.size();
        int temp = 0;
        for(int i = 0; i < n; i++)
        {
            temp = bits[i];
            if(bits[i]==1) {
                i++;
            }
        }
        if(temp == 0) {
            return true;
        }
        return false;
    }
};