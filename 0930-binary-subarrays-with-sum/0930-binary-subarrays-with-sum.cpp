#include <vector>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

private:
    int atMost(const vector<int>& nums, int k) {
        if (k < 0)
        return 0;

        int l = 0;
        long long sum = 0;
        long long cnt = 0;
        
        for (int r = 0; r < (int)nums.size(); ++r) {
            sum += nums[r];
            while (sum > k) {
                sum -= nums[l++];
            }
            cnt += (r - l + 1);
        }
        return (int)cnt;
    }
};
