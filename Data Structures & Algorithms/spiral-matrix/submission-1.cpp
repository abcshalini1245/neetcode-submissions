class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();
        int total = row* column;
        int starting_row = 0;
        int starting_column = 0;
        int ending_row = row-1;
        int ending_column = column-1;
        int count = 0;
        vector<int>ans;
        while(count < total){
          //first row
           for(int i = starting_column; count<total && i<=ending_column; i++){
               ans.push_back(matrix[starting_row][i]);
               count++;
           }
           starting_row++;

           //first row
           for(int i = starting_row; count<total && i<=ending_row; i++){
               ans.push_back(matrix[i][ending_column]);
               count++;
           }
           ending_column--;

           //first row
           for(int i = ending_column; count<total && i>=starting_column; i--){
               ans.push_back(matrix[ending_row][i]);
               count++;
           }
           ending_row--;

           //first row
           for(int i = ending_row; count<total && i>=starting_row; i--){
               ans.push_back(matrix[i][starting_column]);
               count++;
           }
           starting_column++;
        }
        return ans;
    }
};
