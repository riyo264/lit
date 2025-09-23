class Solution {
private:
    vector<int> split(const string& version) {
        vector<int> result;
        string num;
        for (char c : version) {
            if (c == '.') {
                result.push_back(num.empty() ? 0 : stoi(num));
                num.clear();
            } else {
                num.push_back(c);
            }
        }
        if (!num.empty()) result.push_back(stoi(num));
        return result;
    }
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = split(version1);
        vector<int> v2 = split(version2);

        int n = max(v1.size(), v2.size());
        v1.resize(n, 0);
        v2.resize(n, 0);

        for (int i = 0; i < n; i++) {
            if (v1[i] < v2[i]) return -1;
            if (v1[i] > v2[i]) return 1;
        }
        return 0;
    }
};
