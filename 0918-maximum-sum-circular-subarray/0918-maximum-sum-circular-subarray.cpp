class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
     int maxSum=nums[0],currMin=0;
     int minSum=nums[0],currMax=0;
     int totalSum=0;

     for(int num:nums){
        currMax=max(currMax+num,num);
        maxSum=max(maxSum,currMax);

        currMin=min(currMin+num,num);
        minSum=min(minSum,currMin);

        totalSum+=num;
     }   
     if(maxSum<0) return maxSum;
     return max(maxSum,totalSum-minSum);
    }
};