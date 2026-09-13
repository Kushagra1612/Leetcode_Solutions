class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        if(n>m) return false;

        vector<int> s1freq(26,0),windowfreq(26,0);

        for(int i=0;i<n;i++){
            s1freq[s1[i]-'a']++;
            windowfreq[s2[i]-'a']++;
        }
        if (s1freq == windowfreq) return true;

        for(int i=n;i<m;i++){
            windowfreq[s2[i]-'a']++;
            windowfreq[s2[i-n]-'a']--;
            if (s1freq == windowfreq) return true;
        }
        return false;
    }
};