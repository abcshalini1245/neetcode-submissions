class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<bool> rowZero(rows, false);
        vector<bool> colZero(cols, false);

        
        // Step 1: mark rows and columns
        for(int i =0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(matrix[i][j] == 0){
                    rowZero[i] = true;
                    colZero[j] = true;  
                }
                
            }
        }
         // Step 2: set zeros
            for(int i =0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(rowZero[i] || colZero[j]){
                    matrix[i][j]=0; 
                }
                
            }
        }

    }
};
