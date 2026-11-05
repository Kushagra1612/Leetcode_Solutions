class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1,
                             vector<int>& arr2,
                             int d) {
        sort(arr2.begin(), arr2.end());

        int count = 0;
        for (int x : arr1) {

            bool valid = true;
            auto it = lower_bound(
                arr2.begin(), arr2.end(), x
            );

            if (it != arr2.end()) {

                if (abs(x - *it) <= d) {
                    valid = false;
                }
            }

            if (it != arr2.begin()) {

                int previous = *prev(it);

                if (abs(x - previous) <= d) {
                    valid = false;
                }
            }

            if (valid) {
                count++;
            }
        }
        return count;
    }
};