class Solution {
public:
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void BFS(vector<vector<int>>& G, pair<int, int> root) {
        int n = G.size();
        int m = G[0].size();
        queue<pair<int, int>> q;
        q.push(root);
        while (!q.empty()) {
            pair<int, int> curr = q.front(); q.pop();
            for (auto dir : dirs) {
                int r = curr.first + dir.first;
                int c = curr.second + dir.second;
                if (r < 0 || c < 0 || r >= n || c >= m || 
                G[r][c] <= G[curr.first][curr.second] + 1) continue;
                G[r][c] = G[curr.first][curr.second] + 1;
                q.push({r, c});
            }
        }
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    BFS(grid, {i, j});
                }
            }
        }
    }
};
