class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int active=0,first=0,second=0;
        for(int i=0;i<nums.size();i++){

        if(nums[i]%2==1)
        active=1-active;
        
        if(i%6==5)
        active=1-active;

        if(active==0)
        first+=nums[i];

        else
        second+=nums[i];
        }

        return first-second;
    }
};