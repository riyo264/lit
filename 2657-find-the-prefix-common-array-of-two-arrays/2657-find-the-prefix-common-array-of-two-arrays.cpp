class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> visA(n + 1, 0);
        vector<int> visB(n + 1, 0);
        vector<int> C(n);
        int common = 0;
        for (int i = 0; i < n; i++) {
            visA[A[i]] = 1;
            visB[B[i]] = 1;
            if (visA[B[i]] == 1 && visB[A[i]] == 1 && A[i] == B[i]) {
                common++;
            } else if (visA[B[i]] == 1 && visB[A[i]] == 1 && A[i] != B[i]) {
                common += 2;
            } else if (visA[B[i]] == 1 || visB[A[i]] == 1) {
                common++;
            }
            C[i] = common;
        }
        return C;
    }
};