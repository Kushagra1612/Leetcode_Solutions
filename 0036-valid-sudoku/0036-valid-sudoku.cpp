class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> rows[9],cols[9],boxes[9];

        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(board[r][c]=='.') continue;

                char digit=board[r][c];
                int boxIdx=(r/3)*3+(c/3);

            if(rows[r].count(digit) || cols[c].count(digit) || boxes[boxIdx].count(digit)){
                return false;
            }

            rows[r].insert(digit);
            cols[c].insert(digit);
            boxes[boxIdx].insert(digit);
            }
        }
        return true;
    }
};