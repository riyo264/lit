#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n, vector<int>(n, -1));
        for(int i = 0; i < n; i++)
        {
            vector<int> temp;
            int idx = i;
            int j = 0;
            int id = i;
            int k = 0;
            int l = 0;
            while(idx < n && j < n) 
            {
                temp.push_back(grid[idx][j]);
                idx++;
                j++;
            }
            sort(temp.begin(), temp.end());
            reverse(temp.begin(), temp.end());
            while(id < n && k < n)
            {
                ans[id][k] = temp[l];
                id++;
                k++;
                l++;
            }
        }
        for(int i = 1; i < n; i++)
        {
            vector<int> temp;
            int idx = i;
            int j = 0;
            int id = i;
            int k = 0;
            int l = 0;
            while(idx < n && j < n) 
            {
                temp.push_back(grid[j][idx]);
                idx++;
                j++;
            }
            sort(temp.begin(), temp.end());
            while(id < n && k < n)
            {
                ans[k][id] = temp[l];
                id++;
                k++;
                l++;
            }
        }
        return ans;
    }
};
