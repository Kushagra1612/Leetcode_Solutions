class Solution {
public:

 vector<int> getLeftMaxArray(vector<int>& height,int &n){
        vector<int> LeftMax(n);
        LeftMax[0]=height[0];
        for(int i=1;i<n;i++){
            LeftMax[i]=max(LeftMax[i-1],height[i]);
        }
        return LeftMax;
    }
    vector<int> getRightMaxArray(vector<int>& height,int &n){
        vector<int> rightMax(n);
        rightMax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            rightMax[i]=max(rightMax[i+1],height[i]);
        }
        return rightMax;
    }
    int trap(vector<int>& height) {
        int n=height.size();

        vector<int> leftMax=getLeftMaxArray(height,n);
        vector<int> rightMax=getRightMaxArray(height,n);

        int sum=0;

        for(int i=0;i<n;i++){
            int h=min(leftMax[i],rightMax[i]) -height[i];

            sum+=h;
        }
        return sum;
    }
};