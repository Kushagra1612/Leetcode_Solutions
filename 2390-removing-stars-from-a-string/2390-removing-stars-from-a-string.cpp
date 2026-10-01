class Solution {
public:
    string removeStars(string s) {
        int write=0;
        for(char c: s){
            if(c=='*'){
                write--;
            }
            else{
                s[write]=c;
                write++;
            }
        }
        return s.substr(0,write);
    }
};