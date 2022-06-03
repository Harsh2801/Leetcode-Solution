class NumMatrix{
public:
    NumMatrix(vector<vector<int>>& matrix) {
        //prepare prefix sum array
        int rows = matrix.size(), cols = matrix[0].size();
        presum.resize(rows+1, vector<int>(cols+1, 0));
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                //current = matrix + left + up - prev
                presum[r+1][c+1] = matrix[r][c] + presum[r][c+1] + presum[r +1][c] - presum[r][c];
            }
        }
        
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        //return value from cached presum array
        return presum[row2+1][col2+1]-presum[row2+1][col1]-presum[row1][col2+1]+presum[row1][col1];
    }
    vector<vector<int>> presum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */