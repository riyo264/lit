#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<int>> diag;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                diag[i - j].push_back(grid[i][j]);
            }
        }
        for(auto &entry : diag) {
            int key = entry.first;
            if(key >= 0) {
                sort(entry.second.begin(), entry.second.end(), greater<int>());
            } else {
                sort(entry.second.begin(), entry.second.end());
            }
        }

        unordered_map<int,int> idx; 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int key = i - j;
                grid[i][j] = diag[key][idx[key]++];
            }
        }

        return grid;
    }
};
