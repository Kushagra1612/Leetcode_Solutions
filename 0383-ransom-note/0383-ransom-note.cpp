class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for(char ch: ransomNote){
            bool found=false;
            for(int i=0;i<magazine.size();i++){
                if(magazine[i]==ch){
                    magazine[i]='#';
                    found=true;
                    break;
                }
            }
            if(!found){
                return false;
            }
        }
        return true;
    }
};