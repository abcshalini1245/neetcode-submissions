class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {

                if (board[r][c] == '.')
                    continue;

                int d = board[r][c] - '1';   // convert '1'–'9' → 0–8
                int box_idx = (r / 3) * 3 + (c / 3);

                // if already seen → invalid
                if (rows[r][d] || cols[c][d] || boxes[box_idx][d]) {
                    return false;
                }

                // mark as seen
                rows[r][d] = true;
                cols[c][d] = true;
                boxes[box_idx][d] = true;
            }
        }
        return true;
    }
};

