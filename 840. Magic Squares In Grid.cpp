class Solution {
public:

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rowSize = grid.size();
        int colSize = grid[0].size();
        int count = 0;

        // Function to check if a 3x3 subgrid is a magic square
        auto isMagicSquare = [&](int r, int c) {
            // Check bounds
            if (r + 2 >= rowSize || c + 2 >= colSize) {
                return false;
            }
            
            vector<int> nums;
            for (int i = r; i < r + 3; ++i) {
                for (int j = c; j < c + 3; ++j) {
                    nums.push_back(grid[i][j]);
                }
            }

            // Check if numbers are in the range 1 to 9 and distinct
            sort(nums.begin(), nums.end());
            if (nums != vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9})) {
                return false;
            }

            // Check rows, columns, and diagonals
            int sum = grid[r][c] + grid[r][c + 1] + grid[r][c + 2];
            for (int i = r; i < r + 3; ++i) {
                if (grid[i][c] + grid[i][c + 1] + grid[i][c + 2] != sum) {
                    return false;
                }
            }
            for (int j = c; j < c + 3; ++j) {
                if (grid[r][j] + grid[r + 1][j] + grid[r + 2][j] != sum) {
                    return false;
                }
            }
            if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != sum) {
                return false;
            }
            if (grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != sum) {
                return false;
            }

            return true;
        };

        // Check all possible 3x3 subgrids
        for (int i = 0; i <= rowSize - 3; ++i) {
            for (int j = 0; j <= colSize - 3; ++j) {
                if (isMagicSquare(i, j)) {
                    count++;
                }
            }
        }

        return count;
    }
};
