class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        auto lambda = [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        };

        sort(intervals.begin(), intervals.end(), lambda);

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for (int i = 1; i < n; i++) {
            if (result.back()[0] <= intervals[i][0] &&
                result.back()[1] >= intervals[i][1]) {
                continue;   // covered
            }
            result.push_back(intervals[i]);
        }

        return result.size();
    }
};