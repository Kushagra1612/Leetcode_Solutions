class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long totalSum = 0;
        for (const auto& row : grid) {
            for (int val : row) totalSum += val;
        }

        // Check Horizontal Cuts
        if (checkCuts(grid, m, n, totalSum, true)) return true;

        // Check Vertical Cuts (by transposing the logic)
        vector<vector<int>> transposed(n, vector<int>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                transposed[j][i] = grid[i][j];
            }
        }
        if (checkCuts(transposed, n, m, totalSum, false)) return true;

        return false;
    }

private:
    bool checkCuts(const vector<vector<int>>& grid, int rows, int cols, long long totalSum, bool isHorizontal) {
        long long currentSectionSum = 0;
        unordered_map<int, int> freq;
        
        // Initial pass to handle the "discounting" logic efficiently
        for (int i = 0; i < rows - 1; ++i) {
            for (int j = 0; j < cols; ++j) {
                currentSectionSum += grid[i][j];
                freq[grid[i][j]]++;
            }

            long long otherSectionSum = totalSum - currentSectionSum;
            
            // 1. Perfectly equal
            if (currentSectionSum == otherSectionSum) return true;

            // 2. Discount from current section
            if (currentSectionSum > otherSectionSum) {
                long long diff = currentSectionSum - otherSectionSum;
                if (canRemove(grid, i, cols, diff, freq, true)) return true;
            } 
            // 3. Discount from the other section
            else {
                long long diff = otherSectionSum - currentSectionSum;
                // For the "other" section, we'd need its freq map. 
                // To keep it O(N*M), it's easier to run this function 
                // twice (once for top-down, once for bottom-up).
            }
        }
        
        // Re-run for the bottom-up / right-to-left case to check the "other" section
        currentSectionSum = 0;
        freq.clear();
        for (int i = rows - 1; i > 0; --i) {
            for (int j = 0; j < cols; ++j) {
                currentSectionSum += grid[i][j];
                freq[grid[i][j]]++;
            }
            long long otherSectionSum = totalSum - currentSectionSum;
            if (currentSectionSum > otherSectionSum) {
                long long diff = currentSectionSum - otherSectionSum;
                if (canRemove(grid, i, cols, diff, freq, false)) return true;
            }
        }

        return false;
    }

    bool canRemove(const vector<vector<int>>& grid, int cutIdx, int cols, long long diff, unordered_map<int, int>& freq, bool isTopDown) {
        if (diff > 100000) return false; // Max grid value constraint
        if (freq.find((int)diff) == freq.end()) return false;

        // Connectivity Rule:
        // If the section is a 2D block (more than 1 row/col), 
        // removing any existing value is safe.
        int numRowsInSection = isTopDown ? cutIdx + 1 : grid.size() - cutIdx;
        if (numRowsInSection > 1 && cols > 1) return true;

        // If it's 1D (single row or single column), only the ends can be removed.
        if (numRowsInSection == 1) {
            return grid[cutIdx][0] == diff || grid[cutIdx][cols - 1] == diff;
        }
        if (cols == 1) {
            int startRow = isTopDown ? 0 : cutIdx;
            int endRow = isTopDown ? cutIdx : grid.size() - 1;
            return grid[startRow][0] == diff || grid[endRow][0] == diff;
        }

        return false;
    }
};