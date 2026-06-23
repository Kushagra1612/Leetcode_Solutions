class Solution {
public:
    string intToRoman(int num) {
        string roman;
        vector<string> notation={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        vector<int> value={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        for(int i=0;i<notation.size()&& num>0;i++){
            while(num>=value[i]){
             roman+=notation[i];
              num-=value[i];  
            }
        }
        return roman;
    }
};