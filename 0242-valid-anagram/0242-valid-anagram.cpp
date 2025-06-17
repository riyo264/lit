class Solution {
public:
    bool isAnagram(string s, string t) {
       sort(s.begin(), s.end());
       sort(t.begin(), t.end());
       return s == t; 
    }
};


// if(s.size() != t.size()) {
//             return false;
//         }
//         map<char, int> mpp1;
//         for(int i = 0; i < s.size(); i++) 
//         {
//             mpp1[s[i]]++;
//             mpp1[t[i]]--;
//         }
//         for(auto q : mpp1)
//         {
//             if(q.second != 0) {
//                 return false;
//             }
//         }
//         return true;