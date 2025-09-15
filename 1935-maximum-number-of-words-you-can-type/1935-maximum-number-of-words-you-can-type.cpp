class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int cnt = 0;
        bool flag = false;
        unordered_map<char, int> broken;
        
        for(int i = 0; i < brokenLetters.size(); i++)
        {
            broken[brokenLetters[i]]++;
        }
        for(int i = 0; i < text.size(); i++)
        {
            if(text[i] == ' ') {
                if(flag == true) {
                    flag = false;
                    continue;
                }
                else {
                    cnt++;
                    continue;
                }
            }
            if(broken.find(text[i]) != broken.end()) {
                flag = true;
                continue;
            }
            if(i == text.size()-1 && flag == false) {
                cnt++;
            }
        }
        return cnt;
    }
};