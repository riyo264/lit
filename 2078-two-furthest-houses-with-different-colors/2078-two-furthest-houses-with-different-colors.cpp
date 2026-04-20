class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int i = 0, j = n-1;
        int d = 0;
        while(j > i) {
            if(colors[i] != colors[j]) {
                d = abs(j-i);
                break;
            }
            j--;
        }
        j = n-1;
        while(i < j) {
            if(colors[j] != colors[i]) {
                d = max(d, abs(j-i));
                break;
            }
            i++;
        }
        return d;
    }
};