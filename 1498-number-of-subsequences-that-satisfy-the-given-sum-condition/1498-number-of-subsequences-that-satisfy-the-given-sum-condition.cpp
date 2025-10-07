class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
       const int MOD=1e9 + 7;
       std::sort(nums.begin(),nums.end());

       int n=nums.size();

       std::vector<int> power(n);
       power[0]=1;

       for(int i=1;i<n;++i){
        power[i]=(power[i-1]*2)% MOD;
       }
       long long count=0;
       int left=0;
       int right=n-1;
       
       while(left <= right){
        if(nums[left] + nums[right] <= target ){
            count =(count+power[right-left]) % MOD;
            left++;
        }
        else{
            right--;
        }
       }
       return (int) count;

    }
};