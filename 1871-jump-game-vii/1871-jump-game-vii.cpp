class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if(s[n-1] == '1') {
            return false;
        }
        s[0] = 'v';
        int reachable = 0;
        int maxReach = maxJump;
        for(int i = minJump; i < n; i++)
        {
            if(i > maxReach) {
                return false;
            }
            if(s[i-minJump] == 'v') {
                reachable++;
            }
            if(i > maxJump && s[i-maxJump-1] == 'v') {
                reachable--;
            }
            if(reachable > 0 && s[i] == '0') {
                s[i] = 'v';
                maxReach = i + maxJump;
            }
        }
        return reachable;
    }
};