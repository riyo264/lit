class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> bi;
        int j = 0;
        int space = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ') {
                space++;
            }
        }
        if(space != pattern.size()-1) {
            return false;
        }
        for(int i = 0; i < pattern.size(); i++)
        {
            if(bi.find(pattern[i]) == bi.end()) {
                string t;
                while(s[j] != ' ' && j < s.size()) 
                {
                    t.push_back(s[j]);
                    j++;
                }
                j++;
                for(auto c : bi) 
                {
                    if(c.first != pattern[i] && c.second == t) {
                        return false;
                    }
                }
                bi[pattern[i]] = t;
            }
            else {
                string p;
                while(s[j] != ' ' && j < s.size()) 
                {
                    p.push_back(s[j]);
                    j++;
                }
                j++;
                if(bi[pattern[i]] != p) {
                    return false;
                }
            }
        }
        return true;
    }
};