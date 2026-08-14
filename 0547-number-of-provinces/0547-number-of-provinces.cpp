class Solution {
public:

    void dfs(int city, vector<vector<int>>& isConnected,
             vector<bool>& visited) {

        visited[city] = true;

        for (int i = 0; i < isConnected.size(); i++) {

            if (isConnected[city][i] == 1 &&
                !visited[i]) {

                dfs(i, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        vector<bool> visited(n, false);

        int count = 0;

        for (int city = 0; city < n; city++) {

            if (!visited[city]) {

                count++;

                dfs(city, isConnected, visited);
            }
        }

        return count;
    }
};