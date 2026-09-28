class Solution {
public:
    int maxDepth(string s) {
       int ans=0,ctOpening=0;
       for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            ctOpening++;
        }
        else if(s[i]==')'){
            ctOpening--;
        }
        ans=max(ans,ctOpening);
       } 
       return ans;
    }
};