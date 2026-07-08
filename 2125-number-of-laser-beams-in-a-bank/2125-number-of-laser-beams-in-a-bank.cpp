class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int prevdevicecount=0;
        int result=0;
        for(int i=0;i<n;i++){
            int curdevicecount=0;
            for(char &ch:bank[i]){
                if(ch=='1'){
                    curdevicecount++;
                }
            }
            result +=curdevicecount*prevdevicecount;
            if(curdevicecount !=0){
                prevdevicecount=curdevicecount;
            }
        }
        return result;
    }
};