class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int insertpos=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                if(i!=insertpos){
                    nums[insertpos]=nums[i];
                    nums[i]=0;
                }
        insertpos++;
            }
        }
    }
};