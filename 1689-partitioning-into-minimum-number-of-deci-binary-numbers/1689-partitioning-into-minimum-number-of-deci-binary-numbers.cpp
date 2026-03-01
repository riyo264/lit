class Solution {
public:
    int minPartitions(string n) {
        int steps = 0;
        for(int i = 0; i < n.size(); i++)
        {
            steps = max(steps, n[i]-'0');
        }
        return steps;
    }
};