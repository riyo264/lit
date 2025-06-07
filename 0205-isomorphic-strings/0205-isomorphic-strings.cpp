class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> MapS;
        map<char, char> MapT;

        for(int i = 0; i < s.size(); i++)
        {
            if(MapS.contains(s[i])) {
                if(MapS[s[i]] != t[i]) {
                    return false;
                }
            }
            else {
                if(MapT.contains(t[i])) {
                    if(MapT[t[i]] != s[i]) {
                        return false;
                    }
                }
                else {
                    MapS.insert({s[i], t[i]});
                    MapT.insert({t[i], s[i]});
                }
            }
        }
        return true;
    }
};