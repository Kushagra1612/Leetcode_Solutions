class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> numset(nums.begin(),nums.end());
        int longestStreak=0;

        for(int num: numset){
            if(numset.find(num-1)==numset.end()){
               int currnum=num;
               int currstreak=1;
        
            while (numset.find(currnum + 1) != numset.end()) {
                currnum++;
                currstreak++;
            }
        longestStreak=max(longestStreak,currstreak);
        }
    }
    return longestStreak;
    }
};