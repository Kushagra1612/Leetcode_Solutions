class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
       
        unordered_map<int, vector<int>> mp; 
        int result = INT_MAX;

        for (int k = 0; k < n; k++) {
            int val = nums[k];
            mp[val].push_back(k);

            if (mp[val].size() >= 3) {
                int siz = mp[val].size();
               
                int i = mp[val][siz - 3];
                
                result = min(result, 2 * (k - i));
            }
        }

       
        return (result == INT_MAX) ? -1 : result;
    }
};