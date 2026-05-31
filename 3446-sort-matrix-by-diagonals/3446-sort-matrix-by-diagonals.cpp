class Solution {
public:
int n;
    void sortdiagonal(int r,int c,vector<vector<int>>& grid,bool asc){
        vector<int> vec;
        int i=r;
        int j=c;

        while(i<n && j<n){
            vec.push_back(grid[i][j]);
            i++;
            j++;
        }
        if(asc){
            sort(vec.begin(),vec.end());
        }
        else{
            sort(vec.rbegin(),vec.rend());
        }
        i=r;
        j=c;
        for(int&val :vec){
            grid[i][j]=val;
        i++;
        j++;
        
        }
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
         n=grid.size();

        for(int row=0;row<n;row++){
            sortdiagonal(row,0,grid,false);
        }
        for(int col=1;col<n;col++){
            sortdiagonal(0,col,grid,true);
        }
        return grid;
    }
};