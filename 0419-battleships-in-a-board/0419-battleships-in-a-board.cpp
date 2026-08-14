class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        
     int rows = board.size();
    int cols = board[0].size();
    int count = 0;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (board[r][c] == '.') continue;

            // Agar upar ya left me 'X' hai to skip karo
            if (r > 0 && board[r-1][c] == 'X') continue;
            if (c > 0 && board[r][c-1] == 'X') continue;

            // Otherwise ye ek naya ship ka head hai
            count++;
        }
    }
    return count;
}
};