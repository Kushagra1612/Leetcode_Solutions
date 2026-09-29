class Solution {
public:
    string removeDuplicates(string s) {
        bool found=true;
        while(found){
            found =false;
            for(int i=0;i<(int)s.size();i++){
                if(s[i]==s[i+1]){
                    s.erase(i,2);
                    found=true;
                    break;
                }
            }
        }
        return s;
    }
};