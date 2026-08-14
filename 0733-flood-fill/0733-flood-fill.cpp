class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                   int sr, int sc, int color) {

        int n = image.size();
        int m = image[0].size();

        int oldColor = image[sr][sc];

        if (oldColor == color) {
            return image;
        }

        queue<pair<int, int>> q;

        q.push({sr, sc});
        image[sr][sc] = color;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while (!q.empty()) {

            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {

                int newX = x + dx[i];
                int newY = y + dy[i];

                if (newX >= 0 && newX < n &&
                    newY >= 0 && newY < m) {

                    if (image[newX][newY] == oldColor) {

                        image[newX][newY] = color;

                        q.push({newX, newY});
                    }
                }
            }
        }

        return image;
    }
};