class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0].size();
        int old_color = image[sr][sc];

        if(old_color == color){
            return image;
        }

        queue<pair<int,int>> q;
        q.push({sr,sc});

        image[sr][sc] = color;

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int i =0; i<4; i++){
                int nRow = x + dx[i];
                int nCol = y + dy[i];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && image[nRow][nCol] == old_color){
                    image[nRow][nCol] = color;
                    q.push({nRow,nCol});
                }
            }

        }

        return image;

    }
};