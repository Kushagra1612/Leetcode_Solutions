class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int ind=-1;
        for(int i=n-1;i>0;i--){
            if(nums[i] > nums[i-1]){
                ind=i-1;
                break;
            }
        }
        if(ind!=-1) {
        int swap_index=ind;
        for(int j=n-1;j>=ind+1;j--){
            if(nums[j]>nums[ind]){
                swap_index=j;
                break;
            }
        }
        swap(nums[ind],nums[swap_index]);
        }
        reverse(nums.begin()+ind+1,nums.end());
    }
};