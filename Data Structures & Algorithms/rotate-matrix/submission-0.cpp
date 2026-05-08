class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
  //rotate 90 degree = transpose + reverse each row
  //step1: transpose
    int n = matrix.size();
    for(int i =0; i<n; i++){
        for(int j =i; j<n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    //reverse each row
    for(int i =0; i<n; i++){
        reverse(matrix[i].begin(),matrix[i].end());
      }
    }
};
