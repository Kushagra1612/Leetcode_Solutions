class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result=0;
        int zerocount=0;

        for(int num:nums){
            if(num==0){
                zerocount++;
            }
            else{
                result+=zerocount*(zerocount+1LL)/2;
                zerocount=0;
            }
        }
        result+=zerocount*(zerocount+1LL)/2;
        return result;

    }
};