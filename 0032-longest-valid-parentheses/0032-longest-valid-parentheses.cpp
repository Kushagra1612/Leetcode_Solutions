class Solution {
public:
    int longestValidParentheses(string s) {
    //     int maxLen=0;
    //     for(int i=0;i<s.size();i++){
    //         for(int j=i+2;j<=s.size();j+=2){
    //             if(isValid(s,i,j)){
    //                 maxLen=max(maxLen,j-i);
    //             }
    //         }
    //     }
    //     return maxLen;
    // }

    // bool isValid(string& s, int start, int end) {
    // int count = 0;
    // for (int i = start; i < end; i++) {
    //     if (s[i] == '(') count++;
    //     else count--;
    //     if (count < 0) return false;
    // }
    // return count == 0;

    int n=s.size();
    int maxLen=0;
    vector<int> dp(n,0);

    for(int i=1;i<n;i++){
        if(s[i]==')'){
            if(s[i-1]=='('){
                dp[i] = 2 + (i >= 2 ? dp[i - 2] : 0);
            }
            else if(dp[i-1]>0){
                int matchIdx=i-dp[i-1]-1;
                if(matchIdx>=0 && s[matchIdx]=='('){
                    dp[i] = dp[i - 1] + 2 + (matchIdx >= 1 ? dp[matchIdx - 1] : 0);
                }
            }
            maxLen=max(maxLen,dp[i]);
        }
    }
    return maxLen;
}
};