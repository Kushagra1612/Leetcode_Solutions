class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0, r2 =0, s =0, ans = INT_MAX;
        for( r2=0;r2<nums.size();r2++){
            s +=nums[r2];
            while(s >= target){
                ans = min(ans, r2-l+1);
                s = s - nums[l];
                l++;
                }
        }
        if(ans ==INT_MAX) return 0;
        return ans;
    }
};

// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int n = nums.size();
//         vector<int> pref(n);
//         pref[0] = nums[0];
//         int ans = INT_MAX;
//         for (int i = 1; i < n; i++) {
//         //    for (int j = i; j < n; j++) {
//                 pref[i] += pref[i - 1] + nums[i];

//       //      }
//         }
//              for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++) {

//                 int sum;

//                 if (i == 0)
//                     sum = pref[j];
//                 else
//                     sum = pref[j] - pref[i - 1];

//                 if (sum >= target) {
//                     ans = min(ans, j - i + 1);
//                 }
//             }
//         }
//         if(ans == INT_MAX) return 0;
//         return ans;
//     }
// };