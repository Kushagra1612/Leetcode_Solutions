class Solution {
private:
   
    void markGuarded(int row, int col, std::vector<std::vector<int>>& grid) {
        
        for (int i = row - 1; i >= 0; i--) {
           
            if (grid[i][col] == 2 || grid[i][col] == 3) {
                break;
            }
            if (grid[i][col] == 0) {
                grid[i][col] = 1;
            }
        }
        
        for (int i = row + 1; i < grid.size(); i++) {
            if (grid[i][col] == 2 || grid[i][col] == 3) {
                break;
            }
            if (grid[i][col] == 0) {
                grid[i][col] = 1;
            }
        }

        for (int j = col - 1; j >= 0; j--) {
            if (grid[row][j] == 2 || grid[row][j] == 3) {
                break;
            }
            if (grid[row][j] == 0) {
                grid[row][j] = 1;
            }
        }

        for (int j = col + 1; j < grid[0].size(); j++) {
            if (grid[row][j] == 2 || grid[row][j] == 3) {
                break;
            }
            if (grid[row][j] == 0) {
                grid[row][j] = 1;
            }
        }
    }

public:
    int countUnguarded(int m, int n, std::vector<std::vector<int>>& guards, std::vector<std::vector<int>>& walls) {
        
        std::vector<std::vector<int>> grid(m, std::vector<int>(n, 0));

        
        for (const std::vector<int>& vec : guards) {
            int r = vec[0];
            int c = vec[1];
            grid[r][c] = 2; 
        }

        for (const std::vector<int>& vec : walls) {
            int r = vec[0];
            int c = vec[1];
            grid[r][c] = 3; 
        }

        for (const std::vector<int>& vec : guards) {
            int r = vec[0];
            int c = vec[1];
            markGuarded(r, c, grid);
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    count++;
                }
            }
        }
        return count;
    }
};