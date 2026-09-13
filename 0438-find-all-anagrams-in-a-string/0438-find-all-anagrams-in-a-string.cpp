class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int sLen=s.size();
        int pLen=p.size();
        if(sLen<pLen) return result;
        vector<int> pCount(26, 0), windowCount(26, 0);

        for(int i=0;i<pLen;i++){
            pCount[p[i]-'a']++;
            windowCount[s[i]-'a']++;
        }

        if(pCount==windowCount) result.push_back(0);

        for(int i=pLen;i<sLen;i++){
            windowCount[s[i]-'a']++;
            windowCount[s[i-pLen]-'a']--;
            if(pCount==windowCount){
                result.push_back(i-pLen+1);
            }
        }
        return result;
    }
};