class Solution {
public:
    long long minimumSteps(string s) {
        int left=0;
        long long ans=0;

        for(int right=0;right<s.size();right++){
            if(s[right]=='0'){
                ans+=right-left;
                left++;
            }
        }
        return ans;
    }
};