class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        long long windowSum=0;
        long long maxSum=0;

        for(int i=0;i<k;i++){
            freq[nums[i]]++;
            windowSum+=nums[i];
        }
        if((int)freq.size()==k){
            maxSum=windowSum;
        }
        for(int i=k;i<(int)nums.size();i++){
            freq[nums[i]]++;
            windowSum+=nums[i];

        int outval=nums[i-k];
        freq[outval]--;
        if(freq[outval]==0){
            freq.erase(outval);
        }
        windowSum -=outval;

        if((int)freq.size()==k){
            maxSum=max(maxSum,windowSum);
        }
        }
        return maxSum;
    }
};