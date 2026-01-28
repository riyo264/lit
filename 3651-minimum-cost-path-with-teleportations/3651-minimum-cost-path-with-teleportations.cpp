const int M=1e4+1, NN=6400;
const int INF=1e9+7;

// Using an array version for linked list to replace x_pos[M]
static int xList[M], nxt[NN];

static unsigned dp[2][NN]; 
static unsigned suffixMin[M]; 

class Solution {
public:
    static inline int idx(int i, int j, int c) { return i*c+j; }

    static int minCost(vector<vector<int>>& grid, int k) {
        const int r=grid.size(), c=grid[0].size(), N=r*c;

        if (xList[0]!=-1) // fill all with -1 at 1st times
            memset(xList, -1, sizeof(xList));

        int xMax=0;
        // Group indices by values of grid
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                const int x=grid[i][j], p=idx(i, j, c);
                nxt[p]=xList[x];// insert node at 1st place
                xList[x]=p;
                if (x>xMax) xMax=x;
            }
        }

        //Initialize DP for 0th row
        fill(dp[0], dp[0]+N, INF);

        dp[0][0]=0;
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                int pos=idx(i, j, c);
                if (i>0) 
                    dp[0][pos]=min(dp[0][pos], dp[0][pos-c]+grid[i][j]);
                if (j>0) 
                    dp[0][pos]=min(dp[0][pos], dp[0][pos-1]+grid[i][j]);
            }
        }

        // DP with t Teleports
        for (int t=1; t<= k;t++) {
            // &1 trick used here
            const bool curr=t&1, prev=(t-1)&1;

            // Compute suffixMin[x] 
            unsigned currMin=INF;
            for (int x=xMax; x>=0; x--) {
                // trasverse the linked list 
                for (int e=xList[x]; e!=-1; e=nxt[e]) {
                    currMin=min(currMin, dp[prev][e]);
                }
                suffixMin[x]=currMin;// teleport
            }

            // Update cells for current teleport 
            for (int i=0; i<r; i++) {
                for (int j = 0; j < c; j++) {
                    const int pos=idx(i, j, c);
                    const int x=grid[i][j];

                    // best result with fewer teleports or by teleport
                    unsigned best=min(dp[prev][pos], suffixMin[x]);

                    // step from up or Left
                    if (i>0) best=min(best, dp[curr][pos-c]+x);
                    if (j>0) best=min(best, dp[curr][pos-1]+x);

                    dp[curr][pos]=best;
                }
            }
        }
        // Reset for the next test case
        memset(xList, -1, sizeof(int)*(xMax+1));
        return dp[k&1][N-1];
    }
};

// MY SOLUTION USING DP THO GOT A TLE AT 637/880

// class Solution {
// public:
//     const int INF = 1e9;
//     // int solve(int i, int j, vector<vector<int>>& grid, vector<vector<vector<pair<int, int>>>>& tele, int k, vector<vector<vector<int>>>& dp) {
//     //     int n = grid.size();
//     //     int m = grid[0].size();
//     //     if(i < 0 || j < 0 || i >= n || j >= m) {
//     //         return INF;
//     //     }
//     //     if (i == n-1 && j == m-1) return 0;
//     //     if(dp[i][j][k] != -1) return dp[i][j][k];                                   MEMOIZATION
//     //     int cost = INF;
//     //     if(k > 0) {
//     //         for(auto x : tele[i][j]) 
//     //         {
//     //             int u = x.first;
//     //             int v = x.second;
//     //             cost = min(cost, 0 + solve(u, v, grid, tele, k-1, dp));
//     //         }
//     //     }
//     //     if (i + 1 < n)
//     //         cost = min(cost, grid[i+1][j] + solve(i+1, j, grid, tele, k, dp));

//     //     if (j + 1 < m)
//     //         cost = min(cost, grid[i][j+1] + solve(i, j+1, grid, tele, k, dp));
//     //     return dp[i][j][k] = cost;
//     // }
//     int minCost(vector<vector<int>>& grid, int k) {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<vector<pair<int, int>>>> tele(n, vector<vector<pair<int, int>>>(m));
//         vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k+1, INF)));
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < m; j++)
//             {
//                 for(int p = 0; p < n; p++)
//                 {
//                     for(int l = 0; l < m; l++) 
//                     {
//                         if(p == i && l == j) {
//                             continue;
//                         }
//                         if(grid[i][j] >= grid[p][l]) {
//                             tele[i][j].push_back({p, l});
//                         }
//                     }
//                 }
//             }
//         }
//         // return solve(0, 0, grid, tele, k, dp);


//         for(int i = k; i >= 0; i--) {
//             dp[n-1][m-1][i] = 0;
//         }
//         for(int p = 0; p <= k; p++)
//         {
//             for(int i = n-1; i >= 0; i--)
//             {
//                 for(int j = m-1; j >= 0; j--)
//                 {
//                     if (i == n-1 && j == m-1) continue;
//                     int cost = INF;                                                   TABULATION
//                     if(p > 0) {
//                         for(auto x : tele[i][j]) 
//                         {
//                             int u = x.first;
//                             int v = x.second;
//                             cost = min(cost, 0 + dp[u][v][p-1]);
//                         }
//                     }
//                     if (i + 1 < n)
//                         cost = min(cost, grid[i+1][j] + dp[i+1][j][p]);

//                     if (j + 1 < m)
//                         cost = min(cost, grid[i][j+1] + dp[i][j+1][p]);
//                     dp[i][j][p] = cost;
//                 }
//             }
//         }
//         return dp[0][0][k];
//     }
// };