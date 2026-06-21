class Solution {
public:
    string findValidPair(string s) {
       unordered_map<char,int> mp;

       for(int num:s){
            mp[num]++;
       } 
       for(int i=0;i<s.size()-1;i++){
        char a=s[i];
        char b=s[i+1];

        if(a!=b && mp[a]==(a-'0') && mp[b]==(b-'0')){
            return s.substr(i,2);
        }
       }
       return "";
    }
};