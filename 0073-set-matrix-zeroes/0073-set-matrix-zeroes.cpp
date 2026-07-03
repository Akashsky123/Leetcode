class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        bool firstcol = false;

        // Step 1: Mark rows & cols
        for (int i = 0; i < row; i++) {
            if (matrix[i][0] == 0) {
                firstcol = true;
            }
            for (int j = 1; j < col; j++) { // start from 1 (better practice)
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 2: Fill matrix using markers (reverse)
        for (int i = row - 1; i >= 0; --i) {
            for (int j = col - 1; j >= 1; --j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;  
                }
            }
            if (firstcol) {
                matrix[i][0] = 0;
            }
        }
    }
};