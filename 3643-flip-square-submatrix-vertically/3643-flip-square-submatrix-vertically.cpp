class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
         int half = k / 2; //bitwise shift

        for (int col = 0; col < k; col++) {
            int top = x;
            int bottom = x + k - 1;

            for (int row = 0; row < half; row++) {
                swap(grid[top][y + col], grid[bottom][y + col]);
                top++;
                bottom--;
            }
        }

        return grid;
    }
};