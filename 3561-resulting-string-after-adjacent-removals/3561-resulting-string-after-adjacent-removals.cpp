class Solution {
public:
    string resultingString(string s) {
        int i = 0;
        while (i < (int)s.size() - 1) {
            char c1 = s[i];
            char c2 = s[i + 1];

            bool isCircular = (c1 == 'a' && c2 == 'z') || (c1 == 'z' && c2 == 'a');
            bool isAdjacent = abs(c1 - c2) == 1;

            if (isCircular || isAdjacent) {
                s.erase(i, 2);
                i = max(0, i - 1); 
            } else {
                i++;
            }
        }
        return s;
    }
};
