class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix=0,suffix=0;
        int result=nums[0];
        int n=nums.size();

        for(int i=0;i<n;i++){
            prefix=(prefix==0?1:prefix)*nums[i];
            suffix=(suffix==0?1:suffix)*nums[n-1-i];
            result=max(result,max(prefix,suffix));
        }
        return result;
    }
};