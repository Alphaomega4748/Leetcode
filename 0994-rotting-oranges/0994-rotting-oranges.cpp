class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> rotten;
        int total = 0;
        int count = 0;
        int minutes = 0;

        // Count total oranges and push rotten oranges
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] != 0)
                    total++;

                if (grid[i][j] == 2)
                    rotten.push({i, j});
            }
        }

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        while (!rotten.empty()) {

            int size = rotten.size();
            count += size;

            while (size--) {

                auto [x, y] = rotten.front();
                rotten.pop();

                for (int i = 0; i < 4; i++) {

                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                        continue;

                    if (grid[nx][ny] != 1)
                        continue;

                    grid[nx][ny] = 2;
                    rotten.push({nx, ny});
                }
            }

            if (!rotten.empty())
                minutes++;
        }

        return (count == total) ? minutes : -1;
    }
};
