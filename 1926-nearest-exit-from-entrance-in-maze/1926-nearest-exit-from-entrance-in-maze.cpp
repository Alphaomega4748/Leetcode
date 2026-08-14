class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int n = maze.size();
        int m = maze[0].size();
        
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
         
        int steps = 0;
        
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while(!q.empty()){   // FIXED
            int size = q.size();

            for(int i = 0; i < size; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(int k = 0; k < 4; k++){
                    int nRow = x + dr[k];
                    int nCol = y + dc[k];

                    if (nRow >= 0 && nRow < n &&
                        nCol >= 0 && nCol < m &&
                        maze[nRow][nCol] == '.') {

                       
                        if(nRow == 0 || nRow == n-1 || nCol == 0 || nCol == m-1){
                            return steps + 1;
                        }

                        maze[nRow][nCol] = '+';
                        q.push({nRow, nCol});
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};
