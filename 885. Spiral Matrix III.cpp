class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        int total = rows * cols;
        int r = rStart, c = cStart;
        int step = 0; // Tracks how many steps to move in the current direction.
        result.push_back({r, c});
        
        // Directions: right, down, left, up
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0; // Start by moving right

        while (result.size() < total) {
            if (dir == 0 || dir == 2) ++step; // Increase step size after completing a full cycle

            for (int i = 0; i < step; ++i) {
                r += directions[dir].first;
                c += directions[dir].second;
                if (r >= 0 && r < rows && c >= 0 && c < cols) {
                    result.push_back({r, c});
                }
            }
            dir = (dir + 1) % 4; // Change direction
        }

        return result;
    }
};
