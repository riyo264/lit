class Solution {
public:
    const int MOD = 1e9 + 7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        unordered_map<long long, long long> mpp;
        long long len = -1;
        for(int i = 0; i < hFences.size(); i++)
        {
            for(int j = i+1; j < hFences.size(); j++)
            {
                    long long b1 = hFences[i];
                    long long b2 = hFences[j];
                    mpp[abs(b1-b2)]++;
            }
        }
        for(int i = 0; i < vFences.size(); i++)
        {
            for(int j = i+1; j < vFences.size(); j++)
            {
                    long long b1 = vFences[i];
                    long long b2 = vFences[j];
                    if(mpp.count(abs(b1 - b2))) {
                        len = max(len, abs(b1-b2));
                    }
            }
        }
        if(len < 0) {
            return len;
        }
        return (len*len)%MOD;
    }
};