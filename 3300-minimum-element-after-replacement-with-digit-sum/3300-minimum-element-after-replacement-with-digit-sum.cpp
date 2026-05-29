class Solution {
public:
    int digitSum(int n){
         string s=to_string(n);
        int sum=0;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            sum+=c-'0';
        }
        return sum;
    }

    int minElement(vector<int>& nums) {
        int ans=INT_MAX;
       for(int i=0;i<nums.size();i++){
        int x=nums[i];
        ans=min(ans,digitSum(x));
       }
       return ans;
    }
};