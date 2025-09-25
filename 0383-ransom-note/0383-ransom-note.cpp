class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> letters;
        for(int i = 0; i < ransomNote.size(); i++)
        {
            letters[ransomNote[i]]++;
        }
        for(int i = 0; i < magazine.size(); i++)
        {
            if(letters[magazine[i]] != 0) {
                letters[magazine[i]]--;
            }
        }
        for(auto it : letters)
        {
            if(it.second != 0) {
                return false;
            }
        }
        return true;
    }
};