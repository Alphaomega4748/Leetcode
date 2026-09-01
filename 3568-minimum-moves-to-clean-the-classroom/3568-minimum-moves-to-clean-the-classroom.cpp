class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int sr = 0, sc = 0;
        int litter = 0;

        // Each litter gets a bit number
        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                else if (classroom[i][j] == 'L') {
                    id[i][j] = litter++;
                }
            }
        }

        // No litter
        if (litter == 0)
            return 0;

        int masks = 1 << litter;
        int fullMask = masks - 1;

        /*
            State:
            (row, col, energy, mask)

            Encode everything into ONE integer.
        */

        int E = energy + 1;

        auto encode = [&](int r, int c, int e, int mask) {
            return (((r * n + c) * E + e) * masks + mask);
        };

        // Flat visited array -> much faster than 4D vector
        int totalStates = m * n * E * masks;

        vector<bool> visited(totalStates, false);

        // {r, c, energy, mask}
        struct State {
            int r, c, e, mask;
        };

        queue<State> q;

        q.push({sr, sc, energy, 0});

        visited[encode(sr, sc, energy, 0)] = true;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {

            int sz = q.size();

            // One BFS level = one move
            while (sz--) {

                State cur = q.front();
                q.pop();

                int r = cur.r;
                int c = cur.c;
                int e = cur.e;
                int mask = cur.mask;

                // All litter collected
                if (mask == fullMask)
                    return moves;

                // No energy -> cannot move
                if (e == 0)
                    continue;

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Outside grid
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n) {
                        continue;
                    }

                    // Wall
                    if (classroom[nr][nc] == 'X')
                        continue;

                    // Moving costs 1 energy
                    int ne = e - 1;

                    // Collect litter
                    int nmask = mask;

                    if (classroom[nr][nc] == 'L') {
                        nmask |= (1 << id[nr][nc]);
                    }

                    // Reset energy
                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    int stateId = encode(nr, nc, ne, nmask);

                    if (visited[stateId])
                        continue;

                    visited[stateId] = true;

                    q.push({
                        nr,
                        nc,
                        ne,
                        nmask
                    });
                }
            }

            moves++;
        }

        return -1;
    }
};