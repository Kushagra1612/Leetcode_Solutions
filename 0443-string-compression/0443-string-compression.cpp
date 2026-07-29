class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int i=0;
        int index=0;
        while(i<n){
            char curr_chars=chars[i];
            int count=0;

            while(i<n && chars[i]==curr_chars){
                count++;
                i++;
            }
            chars[index]=curr_chars;
            index++;

           if(count>1){
            string string_char=to_string(count);
            for(char &ch:string_char){
            chars[index]=ch;
            index++;
           }
        }
            
        }
        return index;
    }
};