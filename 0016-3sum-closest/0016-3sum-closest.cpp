class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int n = nums.size();

        int closetSum = nums[0] + nums[1] + nums[2];

        if (n < 3)
            return 0;

        sort(nums.begin(), nums.end());

        for (int k = 0; k <= n - 3; k++) {

            int i = k + 1;
            int j = n - 1;

            while (i < j) {

                int sum = nums[i] + nums[j] + nums[k];

                if (abs(target - sum) < abs(target - closetSum))
                    closetSum = sum;

                if (sum < target)
                    i++;

                else if (sum > target)
                    j--;

                else
                    return sum;
            }
        }

        return closetSum;
    }
};