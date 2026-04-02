class Solution {
public:
    int f(int i,int j, int n,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(i==n-1){
            return triangle[n-1][j];
        }
        if(dp[i][j]!=-1e9) return dp[i][j];
        int d=f(i+1,j,n,triangle,dp);
        int dg=f(i+1,j+1,n,triangle,dp);
        return dp[i][j]= triangle[i][j] + min(d,dg);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1e9));
        return f(0,0,n,triangle,dp);
    }
};