class Solution {
public:
    bool rotateString(string s, string goal) {
        char c;
        if(s.size()!=goal.size()) {
            return false;
        }
        for(int i = 0; i < s.size(); i++) 
        {
            c = s[0];
            s.erase(s.begin());
            s.push_back(c);
            if(s == goal) {
                return true;
            }
        }
        return false;
    }
};