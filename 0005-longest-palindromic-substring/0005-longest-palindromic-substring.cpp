class Solution {
public:

    int expandAroundCenter(string s,int left, int right){
        while(left>=0 &&right<s.length() && s[left]==s[right]){
            left--;
            right++;
        }
         return right-left-1;
    }
    string longestPalindrome(string s) {
        
        int n=s.length();
        int start=0;
        int maxLen=0;

        for(int i=0;i<n;i++){
            int oddLen=expandAroundCenter(s,i,i);
            int evenLen=expandAroundCenter(s,i,i+1);

            int len= max(oddLen,evenLen);
        
        if(len>maxLen){
            maxLen=len;

            start=i-(len-1)/2;
        }
        }
        return s.substr(start,maxLen);
    }
};