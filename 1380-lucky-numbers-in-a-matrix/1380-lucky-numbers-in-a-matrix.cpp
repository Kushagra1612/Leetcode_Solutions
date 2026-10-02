class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
      int rows=matrix.size();
      int cols=matrix[0].size();

      vector<int> ans;
      for(int i=0;i<rows;i++){
        int minCol=0;

      for(int j=0;j<cols;j++){
        if(matrix[i][j]<matrix[i][minCol]){
            minCol=j;
        }
      }
      int lucky=matrix[i][minCol];
      bool isLucky= true;

      for(int k=0;k<rows;k++){
        if(matrix[k][minCol] > lucky){
            isLucky=false;
            break;
        }
      }
      if(isLucky){
        ans.push_back(lucky);
      }
      }  
      return ans;
    }
};