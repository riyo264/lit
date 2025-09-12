class Solution {
public:
    // bool sortMap(pair<char, int>& A, pair<char, int>& B) {
    //     return A.second > B.second;
    // }
    string frequencySort(string s) {
        string res;
        map<char, int> mpp;
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            mpp[s[i]]++;
        }
        vector<pair<char, int>> A;
        for(auto& i : mpp) 
        {
            A.push_back(i);
        }
        sort(A.begin(), A.end(), [](pair<char, int>& a, pair<char, int>& b) {
            return a.second > b.second;
        });
        for(auto& it : A)
        {
            for(int i = 0; i < it.second; i++)
            {
                res.push_back(it.first);
            }
        }
        return res;
    }
};