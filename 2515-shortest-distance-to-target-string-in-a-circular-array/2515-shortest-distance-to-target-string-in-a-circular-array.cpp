class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int i = startIndex, j = startIndex;
        int dis = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            if(words[i] == target) {
                int id = abs(i - startIndex);
                dis = min(dis, min(id, n-id));
            }
        }
        if(dis == INT_MAX) {
            return -1;
        }
        return dis;
    }
};