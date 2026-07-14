class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int n=nums.size();
        int actual_sum=n*(n+1)/2;
        int array_sum=0;
        int duplicate_sum=0;
        for(int num:nums){
            array_sum +=num;
        }
        for(int num:s){
            duplicate_sum +=num;
        }
        int missing=actual_sum-duplicate_sum;
        int duplicate=array_sum-duplicate_sum;

        return{duplicate,missing};
    }
};