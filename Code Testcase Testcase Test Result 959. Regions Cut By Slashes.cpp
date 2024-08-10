class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int size = n * n * 4;
        vector<int> parent(size);
        
        // Initialize Union-Find
        iota(parent.begin(), parent.end(), 0);
        
        // Find with path compression
        function<int(int)> find = [&](int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };
        
        // Union
        auto unite = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                parent[rootY] = rootX;
            }
        };
        
        // Traverse the grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int base = 4 * (i * n + j);
                
                // Connect regions within the cell
                if (grid[i][j] == '/') {
                    unite(base, base + 3); // Top with left
                    unite(base + 1, base + 2); // Bottom with right
                } else if (grid[i][j] == '\\') {
                    unite(base, base + 1); // Top with right
                    unite(base + 2, base + 3); // Bottom with left
                } else {
                    // All parts connected for a space
                    unite(base, base + 1);
                    unite(base + 1, base + 2);
                    unite(base + 2, base + 3);
                }
                
                // Connect regions with adjacent cells
                if (i < n - 1) {
                    unite(base + 2, base + 4 * n); // Bottom with top of the cell below
                }
                if (j < n - 1) {
                    unite(base + 1, base + 7); // Right with left of the cell to the right
                }
            }
        }
        
        // Count the number of distinct sets (regions)
        int regions = 0;
        for (int i = 0; i < size; ++i) {
            if (find(i) == i) {
                ++regions;
            }
        }
        
        return regions;
    }
};
