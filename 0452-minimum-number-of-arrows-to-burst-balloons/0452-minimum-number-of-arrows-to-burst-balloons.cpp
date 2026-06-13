bool compare(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),compare);

        int result=1;
        int arrow_pos=points[0][1];
        for(int i=0;i<points.size();i++){
            if(points[i][0] > arrow_pos){
                result++;
                arrow_pos=points[i][1];
            }
        }
        return result;
    }
};