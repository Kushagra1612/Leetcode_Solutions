class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        unordered_set<int> zerorows,zerocols;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    zerorows.insert(i);
                    zerocols.insert(j);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(zerorows.count(i) || zerocols.count(j)){
                    matrix[i][j]=0;
                }
            }
        }
    }
};