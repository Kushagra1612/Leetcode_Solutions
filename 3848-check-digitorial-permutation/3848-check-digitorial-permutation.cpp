class Solution {
public:
    bool isDigitorialPermutation(int n) {
      vector<int> digitorial={1,2,145,40585};

      string s=to_string(n);
      sort(s.begin(),s.end());

      for(int i=0;i<digitorial.size();i++){
        
        int x=digitorial[i];

        string t=to_string(x);
        if(s.length()!=t.length())
        continue;
        
        sort(t.begin(),t.end());
        if(t==s)
        return true;
      }
      return false;
    }
};