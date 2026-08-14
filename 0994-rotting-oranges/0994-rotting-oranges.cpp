class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        int fresh = 0;

        // Rotten oranges queue mein
        // Fresh oranges count
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int mint = 0;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!q.empty() && fresh > 0) {

            int size = q.size();

            for(int i = 0; i < size; i++) {

                int x = q.front().first;
                int y = q.front().second;

                q.pop();

                for(int k = 0; k < 4; k++) {

                    int nRow = x + dr[k];
                    int nCol = y + dc[k];

                    if(nRow >= 0 && nRow < n &&
                       nCol >= 0 && nCol < m &&
                       grid[nRow][nCol] == 1) {

                        grid[nRow][nCol] = 2;

                        fresh--;

                        q.push({nRow, nCol});
                    }
                }
            }

            mint++;
        }

        if(fresh > 0) {
            return -1;
        }

        return mint;
    }
};