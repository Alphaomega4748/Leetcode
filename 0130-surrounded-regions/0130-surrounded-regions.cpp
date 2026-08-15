class Solution {
public:

    void bfs(vector<vector<char>>& board, int r, int c) {

        int n = board.size();
        int m = board[0].size();

        queue<pair<int,int>> q;

        q.push({r, c});
        board[r][c] = '#';

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {

                int nr = x + dr[k];
                int nc = y + dc[k];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    board[nr][nc] == 'O') {

                    board[nr][nc] = '#';
                    q.push({nr, nc});
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        // Top and bottom boundary
        for (int j = 0; j < m; j++) {

            if (board[0][j] == 'O')
                bfs(board, 0, j);

            if (board[n - 1][j] == 'O')
                bfs(board, n - 1, j);
        }

        // Left and right boundary
        for (int i = 0; i < n; i++) {

            if (board[i][0] == 'O')
                bfs(board, i, 0);

            if (board[i][m - 1] == 'O')
                bfs(board, i, m - 1);
        }

        // Final conversion
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (board[i][j] == 'O')
                    board[i][j] = 'X';

                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};