class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) {
            return false;
        }
        map<int, int> freq;
        for (int card : hand) {
            freq[card]++;
        }
        auto it = freq.begin();
        while (it != freq.end()) {
            if (it->second == 0) {
                ++it;
                continue;
            }
            int start = it->first;
            int count = it->second;
            for (int i = 0; i < groupSize; ++i) {
                if (freq[start + i] < count) return false;
                freq[start + i] -= count;
            }
            ++it;
        }
        return true;
    }
};