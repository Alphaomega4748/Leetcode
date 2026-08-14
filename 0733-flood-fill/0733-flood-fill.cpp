class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc,
                                  int color) {

        int n = image.size();
        int m = image[0].size();

        int initialColor = image[sr][sc];

        // If the color is already same
        if(initialColor == color)
            return image;

        queue<pair<int,int>> q;

        q.push({sr, sc});

        image[sr][sc] = color;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while(!q.empty()) {

            auto [row, col] = q.front();
            q.pop();

            // Visit all 4 neighbours
            for(int i = 0; i < 4; i++) {

                int nRow = row + dx[i];
                int nCol = col + dy[i];

                if(nRow >= 0 && nRow < n &&
                   nCol >= 0 && nCol < m &&
                   image[nRow][nCol] == initialColor) {

                    image[nRow][nCol] = color;
                    q.push({nRow, nCol});
                }
            }
        }

        return image;
    }
};