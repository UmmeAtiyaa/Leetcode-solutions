class Solution {
public:
    int numIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int islands = 0;

        auto dfs = [&](int x, int y, auto&& dfs) -> void {
            if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 0 || visited[x][y]) return;
            visited[x][y] = 1;
            dfs(x + 1, y, dfs);
            dfs(x - 1, y, dfs);
            dfs(x, y + 1, dfs);
            dfs(x, y - 1, dfs);
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    islands++;
                    dfs(i, j, dfs);
                }
            }
        }
        return islands;
    }

    int minDays(vector<vector<int>>& grid) {
        int initialIslands = numIslands(grid);

        if (initialIslands != 1) return 0; // Already disconnected

        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (numIslands(grid) != 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }

        return 2; // It always takes at most 2 days
    }
};
