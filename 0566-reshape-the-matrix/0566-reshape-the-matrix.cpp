class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
      int n=mat.size();
      int m=mat[0].size();

      if(m*n!=r*c){
        return mat;
      }

      vector<vector<int>> ans(r,vector<int>(c));

      for(int i=0;i<m*n;i++){
        int oldrow=i/m;
        int oldcol=i%m;

        int newrow=i/c;
        int newcol=i%c;

        ans[newrow][newcol]=mat[oldrow][oldcol];
      }
    return ans;

    }
};