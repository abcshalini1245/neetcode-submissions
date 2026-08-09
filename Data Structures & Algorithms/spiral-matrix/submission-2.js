class Solution {
    /**
     * @param {number[][]} matrix
     * @return {number[]}
     */
    spiralOrder(matrix) {

        let row = matrix.length;
        let column = matrix[0].length;
         let total = row* column;
         let starting_row = 0;
         let starting_column = 0;
         let ending_row = row-1;
         let ending_column = column-1;
         let count = 0;
          let ans = [];
        while(count < total){
          //first row
           for( let i = starting_column; count<total && i<=ending_column; i++){
               ans.push(matrix[starting_row][i]);
               count++;
           }
           starting_row++;

           //first row
           for( let i = starting_row; count<total && i<=ending_row; i++){
               ans.push(matrix[i][ending_column]);
               count++;
           }
           ending_column--;

           //first row
           for( let i = ending_column; count<total && i>=starting_column; i--){
               ans.push(matrix[ending_row][i]);
               count++;
           }
           ending_row--;

           //first row
           for( let i = ending_row; count<total && i>=starting_row; i--){
               ans.push(matrix[i][starting_column]);
               count++;
           }
           starting_column++;
        }
        return ans;
    }
}
