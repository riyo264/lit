class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) {
            return false;
        }
        int cnt = 0;
        int b = 0;
        for(int i = 0; i < word.size(); i++)
        {
            if(word[i] == '@' || word[i] == '#' || word[i] == '$')
            {
                return false;
            }
            else if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
                cnt = 1;
            }
            else if(word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U') {
                cnt = 1;
            }
            else if(word[i] != '0' && word[i] != '1' && word[i] != '2' && word[i] != '3' && word[i] != '4' && word[i] != '5' && word[i] != '6' && word[i] != '7' && word[i] != '8' && word[i] != '9') {
                b = 1;
            }
        }
        if(cnt == 1 && b == 1) {
            return true;
        }
        return false;
    }
};