class Solution {
public:
    int minBitFlips(int start, int goal) {
       int ans=0;
       int xorResult = start ^ goal;
       while(xorResult!=0){
        ans += xorResult & 1;
        xorResult >>=1;
       }
       return ans;
    }
};