class Solution {
public:
    int n, m;
    int t[71][71][71]; 

    int solve(vector<vector<int>>& grid, int row, int c1, int c2) {
        if (row >= m) return 0;

        if (t[row][c1][c2] != -1) return t[row][c1][c2];

        int cherries = grid[row][c1];
        if (c1 != c2) { 
            cherries += grid[row][c2];
        }

       int maxNext = 0;
        for (int i = -1; i <= 1; i++) {     
            for (int j = -1; j <= 1; j++) { 
                int nextC1 = c1 + i;
                int nextC2 = c2 + j;

               
                if (nextC1 >= 0 && nextC1 < n && nextC2 >= 0 && nextC2 < n) {
                    maxNext = max(maxNext, solve(grid, row + 1, nextC1, nextC2));
                }
            }
        }

        return t[row][c1][c2] = cherries + maxNext;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(t, -1, sizeof(t));
        
        
        return solve(grid, 0, 0, n - 1);
    }
};