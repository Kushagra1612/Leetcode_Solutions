class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());

        int n = tiles.size();
        int right = 0;
        int covered = 0;
        int best = 0;

        for (int left = 0; left < n; left++) {
            int start = tiles[left][0];
            
            while (right < n &&
                   tiles[right][1] - start + 1 <= carpetLen) {
                covered += tiles[right][1] - tiles[right][0] + 1;
                right++;
            }

            if (right < n && start + carpetLen > tiles[right][0]) {
                int partial = start + carpetLen - tiles[right][0];
                best = max(best, covered + partial);
            } else {
                best = max(best, covered);
            }

            if (right > left) {
                covered -= tiles[left][1] - tiles[left][0] + 1;
            } else {
                right = left + 1;
            }
        }

        return best;
    }
};