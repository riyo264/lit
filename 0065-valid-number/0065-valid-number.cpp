class Solution {
public:
    bool isNumber(string s) {
        bool numSeen = false;
        bool dotSeen = false;
        bool eSeen = false;
        bool numAfterE = true;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                numSeen = true;
                numAfterE = true;
            }
            else if (c == '.') {
                if (dotSeen || eSeen) return false;
                dotSeen = true;
            }
            else if (c == 'e' || c == 'E') {
                if (eSeen || !numSeen) return false;
                eSeen = true;
                numAfterE = false;
            }
            else if (c == '+' || c == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            else {
                return false;
            }
        }

        return numSeen && numAfterE;
    }
};