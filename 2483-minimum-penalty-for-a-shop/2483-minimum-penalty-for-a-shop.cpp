class Solution {
public:
    int bestClosingTime(string customers) {
        int ans = INT_MAX;
        int ind = customers.size();
        vector<int> pref_penalty(customers.size()+1);
        int penalty = 0;
        for(int i = 0; i < customers.size(); i++)
        {
            if(customers[i] == 'N') {
                penalty++;
            }
        }
        pref_penalty[customers.size()] = penalty;
        for(int i = customers.size()-1; i >= 0; i--)
        {
            if(customers[i] == 'Y') {
                penalty++;
            }
            else {
                penalty--;
            }
            pref_penalty[i] = penalty;
        }
        for(int i = customers.size(); i >= 0; i--)
        {
            if(pref_penalty[i] <= ans) {
                ans = pref_penalty[i];
                ind = i;
            }
        }
        return ind;
    }
};