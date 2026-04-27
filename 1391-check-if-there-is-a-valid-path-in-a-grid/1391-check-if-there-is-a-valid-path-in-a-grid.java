class Solution {
    public boolean hasValidPath(int[][] grid) {
        int m = grid.length, n = grid[0].length;

        int[][][] dir = new int[7][][];

        dir[1] = new int[][]{{0,-1},{0,1}};
        dir[2] = new int[][]{{-1,0},{1,0}};
        dir[3] = new int[][]{{0,-1},{1,0}};
        dir[4] = new int[][]{{0,1},{1,0}};
        dir[5] = new int[][]{{0,-1},{-1,0}};
        dir[6] = new int[][]{{0,1},{-1,0}};

        boolean[][] vis = new boolean[m][n];
        Queue<int[]> q = new LinkedList<>();

        q.offer(new int[]{0,0});
        vis[0][0] = true;

        while(!q.isEmpty()){
            int[] cur = q.poll();
            int r = cur[0], c = cur[1];

            if(r == m-1 && c == n-1)
                return true;

            for(int[] move : dir[grid[r][c]]){
                int nrow = r + move[0];
                int ncol = c + move[1];

                if(nrow<0 || ncol<0 || nrow>=m || ncol>=n || vis[nrow][ncol])
                    continue;

                for(int[] back : dir[grid[nrow][ncol]]){
                    if(nrow + back[0] == r && ncol + back[1] == c){
                        vis[nrow][ncol] = true;
                        q.offer(new int[]{nrow,ncol});
                    }
                }
            }
        }

        return false;
    }
}