class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> lastIndex;
        int left=0;
        int maxSum=0;
        for(int right=0;right<s.size();right++){
            char c=s[right];
            if(lastIndex.count(c) && lastIndex[c] >=left){
                left=lastIndex[c]+1;
            }
            lastIndex[c]=right;
            maxSum=max(maxSum,right-left+1);
        }
        return maxSum;
    }
};