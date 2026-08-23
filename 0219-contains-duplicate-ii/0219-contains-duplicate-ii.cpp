#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> last;
    for (int i = 0; i < nums.size(); i++) {
        if (last.count(nums[i])) {
            int dist = i - last[nums[i]];
            if (dist <= k) {
                return true;
            }
        }
        last[nums[i]] = i;
    }
    return false;
}
};