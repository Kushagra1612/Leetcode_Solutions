class Solution {
public:
    int t[501][501][3];
    int solve(vector<vector<int>>& coins,int i,int j,int neu,int m,int n){
        if(i==m-1 && j==n-1){
            if(coins[i][j]<0 && neu>0){
        return 0;
        }
        return coins[i][j];
        }
        if(i>=m || j>=n){
        return -1e9;
        }
        if(t[i][j][neu] !=-1e9) return t[i][j][neu];
        int take=coins[i][j] + max(solve(coins,i,j+1,neu,m,n),solve(coins,i+1,j,neu,m,n));
        
        int skip=-1e9;
        if(coins[i][j]<0 && neu>0){
            int skipdown=solve(coins,i+1,j,neu-1,m,n);
            int skipright=solve(coins,i,j+1,neu-1,m,n);

            skip=max(skipdown,skipright);
        }
         return t[i][j][neu]= max(take,skip);
    }
   

    int maximumAmount(vector<vector<int>>& coins) {
       int m=coins.size();
       int n=coins[0].size();
        for(int i=0;i<501;i++){
            for(int j=0;j<501;j++){
                for(int k=0;k<3;k++){
                    t[i][j][k]=-1e9;
                }
            }
        }
        return solve(coins,0,0,2,m,n);
    }
};